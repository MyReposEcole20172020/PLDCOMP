#include "DefVar.h"

string DefVarWithDeclar::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    cfg->add_to_symbol_table(left,*myType);
	myVar->setType(*myType);
    //rvalue
    string right = myExpr->buildIR(cfg);
	
	Type t1 = *myType;
	Type t2 = myExpr->getType();
	Type type("unknown");
	if(t1.getTypeValue() > t2.getTypeValue()){
		type = t1;
	}else{
		type = t2;
	}

	if(cfg->get_var_type(right).getText() != type.getText()){
		string var = cfg->create_new_tempvar(type);
		Type typeInt("int64_t");
        string varTemp = cfg->create_new_tempvar(typeInt);
        int offset = cfg->get_var_index(var);
        vector<string> params1;
        params1.push_back(varTemp);
        params1.push_back(to_string(offset));
        vector<string> params2;
        params2.push_back(varTemp);
        params2.push_back("!bp");
        params2.push_back(varTemp);
        cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
        cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
		vector<string> params;
        params.push_back(varTemp);
        params.push_back(right);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(right),params);
		right = var;
	}

    //Get the address of the variable
    Type typeInt("int64_t");
    string var = cfg->create_new_tempvar(typeInt);
    int offset = cfg->get_var_index(left);
    vector<string> params1;
    params1.push_back(var);
    params1.push_back(to_string(offset));
    vector<string> params2;
    params2.push_back(var);
    params2.push_back("!bp");
    params2.push_back(var);
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params1);
    cfg->current_bb->add_IRInstr(IRInstr::add,typeInt,params2);
    //Assignment
    vector<string> params3;
    params3.push_back(var);//Here, we use the value in var
    params3.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    return left;
}


