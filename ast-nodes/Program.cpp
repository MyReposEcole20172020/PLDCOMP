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
		if(i != j && dynamic_cast<DefFunc*>(funcs[i]) != nullptr && dynamic_cast<DefFunc*>(funcs[j]) != nullptr){
			if(funcs[i]->getName() == funcs[j]->getName()){
				cerr << "Error : Redefinition of function :" << funcs[i]->getName() << endl;
				exit(0); 
			}
		}
		if(i != j && dynamic_cast<DecFunc*>(funcs[i]) != nullptr && dynamic_cast<DecFunc*>(funcs[j]) != nullptr){
			if(funcs[i]->getName() == funcs[j]->getName()){
				cerr << "Error : Redeclaration of function :" << funcs[i]->getName() << endl;
				exit(0); 
			}
		}
	}
    }
}

void Program::verifierDeclaration(Function* func){
    int size = funcs.size();
    for(int i = 0; i < size; i++){
		if(dynamic_cast<DefFunc*>(funcs[i]) != nullptr){
			if(funcs[i]->getName() == func->getName() && funcs[i]->getReturnType()->getText() == func->getReturnType()->getText()){
				if(func->getParams() == nullptr){
					if(funcs[i]->getParams() == nullptr){
						return;
					}
				}else{
					if(funcs[i]->getParams() != nullptr){
					if(func->getParams()->getParameters().size() == funcs[i]->getParams()->getParameters().size()){
						 for (int j = 0 ; j < func->getParams()->getParameters().size(); j++){
			if(func->getParams()->getParameters()[j]->getType()->getText() == funcs[i]->getParams()->getParameters()[j]->getType()->getText()){
				if(j == func->getParams()->getParameters().size()-1){
				return;
			}
					}
				}					
					}
				}
				}				
			}
		}
    }
	cerr << "Error : No corresponding definition of function :" << func->getReturnType()->getText()+" " << func->getName() << "( " ;
	if(func->getParams() != nullptr){
	for (int j = 0 ; j < func->getParams()->getParameters().size(); j++)
	    {
		cerr << func->getParams()->getParameters()[j]->getType()->getText() << " ";
	}
	}
	cerr << ")" << endl;
	exit(0);
}

string Program::buildIR(){
    for(Function* func : funcs){
	if(dynamic_cast<DefFunc*>(func) != nullptr) {
		CFG* cfg = new CFG(func,this);
		func->buildIR(cfg);
		cfgs.push_back(cfg);
	}
    }
	return "";
}

void Program::verifierDeclarations(){
	for(Function* func : funcs){
	if(dynamic_cast<DecFunc*>(func) != nullptr) {
		verifierDeclaration(func);
	}
    }

}

void Program::generateCode(ofstream& o){
	verifierRedefinition();
	verifierDeclarations();
	o << ".text " << endl;
	for(CFG* cfg : cfgs){
		if (cfg == nullptr) {
			continue;
		}
		cfg->gen_asm(o);
	}
}

Type* Program::getFuncReturn(string name){
	Type* returnType = nullptr;
	for(Function* func : funcs){
		if(dynamic_cast<DefFunc*>(func) != nullptr) {
			if(func->getName() == name){
				returnType = func->getReturnType();
			}
		}
	}
	return returnType;
}
