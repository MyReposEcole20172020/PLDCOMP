#include "ExecFuncNormal.h"
#include "Program.h"

ExecFuncNormal::~ExecFuncNormal(){
    delete myParams;
}

string ExecFuncNormal::buildIR(CFG* cfg){
	string left;
	if(cfg->prog->getFuncReturn(funcName) == nullptr){
		cerr << "Error: there is no definition of function (" << funcName << ") before the call of this function" <<endl;
		exit(0); 
	}else{
	type = *(cfg->prog->getFuncReturn(funcName));
	left = cfg->create_new_tempvar(type);
	vector<string> funcParams;
	if(myParams != nullptr){
		funcParams = myParams->buildIR(cfg);
	}
    vector<string> params;
    params.push_back(left);
    params.push_back(funcName);
    for(string s : funcParams){
		params.push_back(s);
    }
    cfg->current_bb->add_IRInstr(IRInstr::call,type,params);
	}
	return left;
}
