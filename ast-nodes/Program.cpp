#include "Program.h"
#include "../gen-assembly/CFG.h"

Program::Program(){
}

Program::~Program() { 
    size_t length = funcs.size();
    for(size_t i = 0; i < length; i++){
        delete funcs[i];
    }
    funcs.clear();
}

void Program::verifierRedefinition(){
    int size = funcs.size();
    for(int i = 0; i < size; i++){
	for(int j = 0; j < size;j++){
		if(i != j){
			if(funcs[i]->getName() == funcs[j]->getName()){
				cerr << "Error : Redefinition of function :" << funcs[i]->getName() << endl;
				exit(0); 
			}
		}
	}
    }
}

string Program::buildIR(){
    for(Function* func : funcs){
        CFG* cfg = new CFG(func,this);
        func->buildIR(cfg);
        cfgs.push_back(cfg);
    }
	return "";
}

void Program::generateCode(ofstream& o){
	verifierRedefinition();
	o << ".text " << endl;
	for(CFG* cfg : cfgs){
	    //cout << cfg->ast->getName() << endl;
		if (cfg == nullptr) {
			continue;
		}
		cfg->gen_asm(o);
	}
}

Type* Program::getFuncReturn(string name){
	Type* returnType = nullptr;
	for(Function* func : funcs){
		if(func->getName() == name){
			returnType = func->getReturnType();
		}
	}
	return returnType;
}
