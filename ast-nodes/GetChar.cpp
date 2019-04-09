#include "GetChar.h"

GetChar::~GetChar(){
}

string GetChar::buildIR(CFG* cfg){
	string left = cfg->create_new_tempvar(Type("char"));
	vector<string> params;
	params.push_back(left);
	params.push_back(funcName);
	Type typeChar("char");
	cfg->current_bb->add_IRInstr(IRInstr::call,typeChar,params);
    return left;
}
