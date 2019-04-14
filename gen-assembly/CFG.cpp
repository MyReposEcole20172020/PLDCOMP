#include "CFG.h"
#include "../ast-nodes/Function.h"

CFG::CFG(Function * func, Program* oneProg) {
	ast = func;
	BasicBlock* bb = new BasicBlock(this, "." + ast->getName());
	bbs.push_back(bb);
	current_bb = bb;
	BasicBlock* bbExit = new BasicBlock(this, ".EPILOG" + ast->getName());
	bbs.push_back(bbExit);
	current_bb->set_exit_true(bbExit);
	bbExit->set_exit_true(nullptr);
	prog = oneProg;
	nextFreeSymbolIndex = 0;
	nextBBnumber = 1;
	currentBlockDepth = 0;
	currentScopeIndex = 0;
	/*map <string, int> SymbolIndexMap;
	SymbolIndex.push_back(SymbolIndexMap);
	map <string, Type> SymbolTypeMap;
	SymbolType.push_back(SymbolTypeMap);*/
	Scope* first = new Scope;
	first->myIndex = currentScopeIndex;
	first->parent = nullptr;
	allScope.push_back(first);
	scopeIR.push_back(first);
	add_to_symbol_table("retValue", *(ast->getReturnType()));
}

void CFG::add_bb(BasicBlock* bb) {
    BasicBlock* bbExit = bbs.back();
    bbs.pop_back();
    bbs.push_back(bb);
    bbs.push_back(bbExit);
	nextBBnumber += 1;
}

string CFG::new_BB_name() {
    return ".LBB_" + ast->getName() + "_" + to_string(nextBBnumber);
}

void CFG::gen_asm(ostream& o) {
	o << "	.globl	" << ast->getName() << endl; /*<< "(";
	for (int i = 0 ; i < ast->getParams()->getParameters().size(); i++)
	{
	    o << ast->getParams()->getParameters()[i]->getType()->getText();
	    if (i < ast->getParams()->getParameters().size()-1) {
	        o << ", ";
	    }
	}
	o << ")" << endl;*/
	o << ast->getName() << ":" << endl;
	gen_asm_prologue(o);
	for (BasicBlock* bb: bbs) {
		bb->gen_asm(o);
	}
	/*o << endl;
	gen_asm_epilogue(o);*/
}

string CFG::IR_reg_to_asm(string reg) {
	/*vector<map<string, int>>::reverse_iterator rit;
	for(rit = SymbolIndex.rbegin(); rit != SymbolIndex.rend(); rit++){
    	map<string, int>::iterator index = rit->find(reg);
		if (index != rit->end()) {
			return("-"+ to_string(index->second) + "(%rbp)");
		}
	}*/
	int length = scopeIR.size();
	for(int i = length-1; i >= 0; i--){
    		auto index = scopeIR[i]->SymbolIndex.find(reg);
		if (index != scopeIR[i]->SymbolIndex.end()) {
			return("-"+ to_string(index->second) + "(%rbp)");
		}
	}
	cerr << "Error : Variable \'" << reg << "\' was not declared \n";
	return("Erreur");
}

void CFG::gen_asm_prologue(ostream& o) {
	string pro = ".PROLOG" + ast->getName() +" : \n";
    pro += "	pushq   %rbp\n";
    pro += "	movq    %rsp, %rbp\n";
    pro += "	subq    $";
    pro += to_string(nextFreeSymbolIndex+8);
    pro += ",   %rsp\n";
    if (ast->getParams() != nullptr) {
	    for (int i = 0 ; i < ast->getParams()->getParameters().size(); i++)
	    {
	        //int offset = get_var_index(ast->getParams()->getParameters()[i]->getName());
		int offset = get_var_index_asm(ast->getParams()->getParameters()[i]->getName(),0);
	        pro += "	movq	%" + param_register[i] + ", " + to_string(offset) + "(%rbp) \n";
	    }
	}
	o << pro << endl;
}

void CFG::gen_asm_epilogue(ostream& o) {
	string epi = "";
    //Type retType = get_var_type("retValue");
	Type retType = get_var_type_asm("retValue",0);
	if(retType.getText() != "void"){
        //int offset = get_var_index("retValue");
	int offset = get_var_index_asm("retValue",0);
        if(retType.getText() == "int64_t"){
			epi += "	movq  ";
			epi += to_string(offset) + "(%rbp), %rax\n";
		}else if(retType.getText() == "int"){
			epi += "	movl  ";
			epi += to_string(offset) + "(%rbp), %eax\n";
		}else if(retType.getText() == "char"){
			epi += "	movb  ";
			epi += to_string(offset) + "(%rbp), %al\n";
			epi += "	movsbl	%al, %eax\n";
		}
	}
    epi += "	addq    $";
    epi += to_string(nextFreeSymbolIndex+8);
    epi += ",   %rsp\n";
    epi += "	popq   %rbp\n";
    epi += "	retq\n";
	o << epi;
}

// symbol table methods
void CFG::add_to_symbol_table(string name, Type t, int tableSize) {
	if (scopeIR[currentBlockDepth]->SymbolIndex.find(name) != scopeIR[currentBlockDepth]->SymbolIndex.end()) {
		cerr << "Error : Redeclaration of  \'" << name << "\'\n";
		cerr << "The variable \'" << name << "\' will still remain at its old address \n";
		exit(0);
		return;
	}
	scopeIR[currentBlockDepth]->SymbolType.insert(make_pair(name,t));
	if(t.getText() == "int64_t" || t.getText() == "int*"  || t.getText() == "char*"|| t.getText() == "int64_t*"){
		nextFreeSymbolIndex +=8;
	}else if(t.getText() == "int"){
		nextFreeSymbolIndex +=4;
	}else if(t.getText() == "char"){
		nextFreeSymbolIndex +=4;
	}
	scopeIR[currentBlockDepth]->SymbolIndex.insert(make_pair(name,nextFreeSymbolIndex));
	nextFreeSymbolIndex += tableSize;	
}

string CFG::create_new_tempvar(Type t) {
	string name;
	if(t.getText() == "int"){
		name = "!tmp" + to_string(nextFreeSymbolIndex+4);
	}else if(t.getText() == "int64_t"){
		name = "!tmp" + to_string(nextFreeSymbolIndex+8);
	}else if(t.getText() == "char"){
		name = "!tmp" + to_string(nextFreeSymbolIndex+4);
	}
	add_to_symbol_table(name,t);
	return name;
}

int CFG::get_var_index(string name) {
	//vector<Scope*>::reverse_iterator rit;
	/*for(rit = scopeIR.rbegin(); rit != scopeIR.rend(); rit++){
    	auto index = rit->find(name);
		if (index != rit->end()) {
			return(-1*index->second);
		}
	}*/
	int length = scopeIR.size();
	for(int i = length-1; i >= 0; i--){
    		auto index = scopeIR[i]->SymbolIndex.find(name);
		if (index != scopeIR[i]->SymbolIndex.end()) {
			return(-1*index->second);
		}
	}
	cerr << "Error : Variable \'" << name << "\' not declared\n";
	exit(0);
	return -1;
}

int CFG::get_var_index_asm(string name, int scopeIndex) {
	//vector<Scope*>::reverse_iterator rit;
	/*for(rit = scopeIR.rbegin(); rit != scopeIR.rend(); rit++){
    	auto index = rit->find(name);
		if (index != rit->end()) {
			return(-1*index->second);
		}
	}*/
	int length = allScope.size();
	Scope* scope = nullptr;
	for(int i = 0; i < length; i++){
    		if(allScope[i]->myIndex == scopeIndex){
			scope = allScope[i];
			break;
		}
	}
	return find_var_index(scope,name);
}

int CFG::find_var_index(Scope* scope, string name){
	int ind;
	auto index = scope->SymbolIndex.find(name);
	if (index != scope->SymbolIndex.end()) {
		ind = -1*index->second;
	}else{
		if(scope->parent != nullptr){
			ind = find_var_index(scope->parent, name);
		}else{
			ind = -1;
			cerr << "Error : Variable \'" << name << "\' not declared\n";
			exit(0);
		}
	}
	return ind;
}

Type CFG::get_var_type(string name) {
	/*vector<map <string, Type>>::reverse_iterator rit;
	for(rit = SymbolType.rbegin(); rit != SymbolType.rend(); rit++){
    	auto t = rit->find(name);
		if (t != rit->end()) {
			return(t->second);
		}
	}*/
	int length = scopeIR.size();
	
	for(int i = length-1; i >= 0; i--){
    		auto t = scopeIR[i]->SymbolType.find(name);
		if (t != scopeIR[i]->SymbolType.end()) {
			return(t->second);
		}
	}
	return Type("unknown");
}

Type CFG::get_var_type_asm(string name, int scopeIndex) {
	/*vector<map <string, Type>>::reverse_iterator rit;
	for(rit = SymbolType.rbegin(); rit != SymbolType.rend(); rit++){
    	auto t = rit->find(name);
		if (t != rit->end()) {
			return(t->second);
		}
	}*/
	int length = allScope.size();
	Scope* scope = nullptr;
	for(int i = 0; i < length; i++){
    		if(allScope[i]->myIndex == scopeIndex){
			scope = allScope[i];
			break;
		}
	}
	return find_var_type(scope,name);
}

Type CFG::find_var_type(Scope* scope, string name){
	auto t = scope->SymbolType.find(name);
	if (t != scope->SymbolType.end()) {
		return(t->second);
	}else{
		if(scope->parent != nullptr){
			return find_var_type(scope->parent, name);
		}else{
			cerr << "Error : Variable \'" << name << "\' not declared\n";
			exit(0);
			return (Type("unknown"));
		}
	}
	return (Type("unknown"));
}
