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
	auto index = SymbolIndex.find(reg);
	if (index == SymbolIndex.end()) {
		return("Erreur");
	}
	return("-"+ to_string(index->second) + "(%rbp)");
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
	        int offset = get_var_index(ast->getParams()->getParameters()[i]->getName());
	        pro += "	movq	%" + param_register[i] + ", " + to_string(offset) + "(%rbp) \n";
	    }
	}
	o << pro << endl;
}

void CFG::gen_asm_epilogue(ostream& o) {
	string epi = "";
    Type retType = get_var_type("retValue");
	if(retType.getText() != "void"){
        int offset = get_var_index("retValue");
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
	SymbolType.insert(make_pair(name,t));
	if(t.getText() == "int64_t" || t.getText() == "int*"  || t.getText() == "char*"){
		nextFreeSymbolIndex +=8;
	}else if(t.getText() == "int"){
		nextFreeSymbolIndex +=4;
	}else if(t.getText() == "char"){
		nextFreeSymbolIndex +=4;
	}
	SymbolIndex.insert(make_pair(name,nextFreeSymbolIndex));
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
	auto index = SymbolIndex.find(name);
	if (index == SymbolIndex.end()) {
		return(1);
	}
	return(-1*index->second);
}

Type CFG::get_var_type(string name) {
	auto t = SymbolType.find(name);
	if (t == SymbolType.end()) {
		return(Type("unknown"));
	}
	return(t->second);
}
