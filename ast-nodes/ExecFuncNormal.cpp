#include "ExecFuncNormal.h"
#include "Program.h"

ExecFuncNormal::~ExecFuncNormal(){
    delete myParams;
}

string ExecFuncNormal::buildIR(CFG* cfg){
	type = *(cfg->prog->getFuncReturn(funcName));
	string left = cfg->create_new_tempvar(type);
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
	return left;
}
