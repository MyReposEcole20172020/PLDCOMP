#include "ElemRv.h"
#include "../gen-assembly/CFG.h"

ElemRv::~ElemRv(){
    delete myExpr;
}

string ElemRv::buildIR(CFG* cfg){
	string index = myExpr->buildIR(cfg);
	string tabType = cfg->get_var_type(arrayName).getText();
	if(tabType == "int*"){
	    type = Type("int");
	}else if(tabType == "char*"){
	    type = Type("char");
	} 
	Type type64("int64_t");
	string var = cfg->create_new_tempvar(type64);
	vector<string> params;
	params.push_back(var);
	if(tabType == "int*"){
	    params.push_back(to_string(8));
	}else if(tabType == "char*"){
	    params.push_back(to_string(8));
	} 
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,type64,params);
	string var1;
	string var2;
	string var3;
	var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params1;
    params1.push_back(var3);
    params1.push_back(index);
    params1.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::mul,type64,params1);
    var1 = cfg->create_new_tempvar(this->getType());
    vector<string> params2;
    params2.push_back(var1);
    params2.push_back(var3);
    params2.push_back(arrayName);
    cfg->current_bb->add_IRInstr(IRInstr::add,type64,params2);
    vector<string> params4;
    params4.push_back(var1);
    params4.push_back("!bp");
    params4.push_back(var1);
    cfg->current_bb->add_IRInstr(IRInstr::add,type64,params4);
    var2 = cfg->create_new_tempvar(this->getType());
    vector<string> params3;
    params3.push_back(var2);
    params3.push_back(var1);
    cfg->current_bb->add_IRInstr(IRInstr::rmem,this->getType(),params3);
	return var2;
}
