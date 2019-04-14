#include "ElemLv.h"
#include "../gen-assembly/CFG.h"

ElemLv::~ElemLv(){
    delete myExpr;
}

string ElemLv::buildIR(CFG* cfg){
	string index = myExpr->buildIR(cfg);
	
	Type typeInt("int64_t");
	string var5 = cfg->create_new_tempvar(typeInt);
	//string varTemp = cfg->create_new_tempvar(typeInt);
	//Give 0 as the intial value of var5
	vector<string> params10;
	params10.push_back(var5);
	params10.push_back("0");
	cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params10);
	//Copy the value of index
	//int offset = cfg->get_var_index(var5);
	/*vector<string> params5;
	params5.push_back(varTemp);
	params5.push_back(to_string(offset));
	vector<string> params6;
	params6.push_back(varTemp);
	params6.push_back("!bp");
	params6.push_back(varTemp);
	cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params5);
	cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params6);
	vector<string> param7;
	param7.push_back(varTemp);
	param7.push_back(index);
	cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(index),param7);*/
	vector<string> params5;
	params5.push_back(var5);
	params5.push_back(index);
	cfg->current_bb->add_IRInstr(IRInstr::copy,cfg->get_var_type(index),params5);
	index = var5;

	string tabType = cfg->get_var_type(arrayName).getText();
	if(tabType == "int*"){
	    type = Type("int");
	}else if(tabType == "char*"){
	    type = Type("char");
	}else if(tabType == "int64_t*"){
	    type = Type("int64_t");
	} 
	Type type64("int64_t");
	string var = cfg->create_new_tempvar(type64);
	vector<string> params;
	params.push_back(var);
	if(tabType == "int*"){
	    params.push_back(to_string(4));
	}else if(tabType == "char*"){
	    params.push_back(to_string(4));
	}else if(tabType == "int64_t*"){
	    params.push_back(to_string(8));
	}  
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,type64,params);
	string var1;
	string var2;
	string var3;
	var3 = cfg->create_new_tempvar(type64);
    vector<string> params1;
    params1.push_back(var3);
    params1.push_back(index);
    params1.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::mul,type64,params1);
    var1 = cfg->create_new_tempvar(type64);
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
	return var1;
}
