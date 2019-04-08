#include "GetChar.h"

GetChar::~GetChar(){
}

string GetChar::buildIR(CFG* cfg){
	vector<string> params;
	params.push_back("");
	params.push_back(funcName);
	Type typeChar("char");
	cfg->current_bb->add_IRInstr(IRInstr::call,typeChar,params);
    return "";
}
