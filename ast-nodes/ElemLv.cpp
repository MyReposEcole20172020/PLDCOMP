#include "ElemLv.h"
#include "../gen-assembly/CFG.h"

ElemLv::~ElemLv(){
    delete myExpr;
}

string ElemLv::buildIR(CFG* cfg){
	string index = myExpr->buildIR(cfg);
	string tabType = cfg->get_var_type(arrayName).getText();
	if(tabType == "int*"){
	    type = Type("int");
	}else if(tabType == "char*"){
	    type = Type("char");
	} 
	string var = cfg->create_new_tempvar(this->getType());
	vector<string> params;
	params.push_back(var);
	if(tabType == "int*"){
	    params.push_back(to_string(8));
	}else if(tabType == "char*"){
	    params.push_back(to_string(8));
	} 
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
	string var1;
	string var2;
	string var3;
	var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params1;
    params1.push_back(var3);
    params1.push_back(index);
    params1.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::mul,this->getType(),params1);
    var1 = cfg->create_new_tempvar(this->getType());
    vector<string> params2;
    params2.push_back(var1);
    params2.push_back(var3);
    params2.push_back(arrayName);
    cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params2);
    vector<string> params4;
    params4.push_back(var1);
    params4.push_back("!bp");
    params4.push_back(var1);
    cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params4);
	return var1;
}
