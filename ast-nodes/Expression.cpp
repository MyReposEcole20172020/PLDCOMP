#include "Expression.h"
#include "ElemLv.h"
#include "../gen-assembly/CFG.h"

string ExprInt::buildIR(CFG * cfg){
    string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    params.push_back(to_string(value));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
    return var;
}

string ExprVar::buildIR(CFG * cfg){
	type = cfg->get_var_type(myName);
    return myName;
}

string ExprChar::buildIR(CFG * cfg){
    string var = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var);
    int valueInt = (int)value;
    params.push_back(to_string(valueInt));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
    return var;
}

string ExprBinary::buildIR(CFG * cfg){
    OPTYPE value = myOp->getValue();
    string var1 = op1->buildIR(cfg);
    string var2 = op2->buildIR(cfg);
	evalType();
	if(cfg->get_var_type(var1).getText() != type.getText()){
		string var = cfg->create_new_tempvar(this->getType());
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
        params.push_back(var1);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(var1),params);
		var1 = var;
	}
	if(cfg->get_var_type(var2).getText() != type.getText()){
		string var = cfg->create_new_tempvar(this->getType());
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
        params.push_back(var1);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(var1),params);
		var1 = var;
	}
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    switch(value){
        case ADD:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params);
            break;
        case SUB:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),params);
            break;
        case MULT:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::mul,this->getType(),params);
            break;
        case DIV:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::div,this->getType(),params);
            break;
		case MOD:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::mod,this->getType(),params);
            break;
		case ANDBIN:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::and_bin,this->getType(),params);
            break;
		case OUEXBIN:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::ou_ex_bin,this->getType(),params);
            break;
		case OUBIN:
            params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::ou_bin,this->getType(),params);
            break;
		case GREAT:
			params.push_back(var3);
            params.push_back(var2);
            params.push_back(var1);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_lt,this->getType(),params);
            break;
		case LESS:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_lt,this->getType(),params);
            break;
		case GREATEQ:
			params.push_back(var3);
            params.push_back(var2);
            params.push_back(var1);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_le,this->getType(),params);
            break;
		case LESSEQ:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_le,this->getType(),params);
            break;
		case EQUAL:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_eq,this->getType(),params);
            break;
		case UNEQUAL:
			params.push_back(var3);
            params.push_back(var1);
            params.push_back(var2);
            cfg->current_bb->add_IRInstr(IRInstr::cmp_neq,this->getType(),params);/*ueq*/
            break;
		default:
	    	break;   
    }
    return var3;
}

string ExprUnary::buildIR(CFG * cfg){
    OPTYPE value = myOp->getValue();
    string var = op->buildIR(cfg);
	evalType();
	string returnStr = "";
	vector<string> params;
	string tmp = cfg->create_new_tempvar(this->getType());
	params.push_back(tmp);
	params.push_back("1");
	cfg->current_bb->add_IRInstr(IRInstr::ldconst,this->getType(),params);
	vector<string> para1;
	vector<string> para2;
	vector<string> para3;
	string tmp1 = "";
	string tmp2 = "";
    switch(value){
        case POSTINC:
			tmp1 = cfg->create_new_tempvar(this->getType());
			para1.push_back(tmp1);
			para1.push_back(var);
			cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para1);
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = tmp1;
            break;
        case POSTDEC:
			tmp1 = cfg->create_new_tempvar(this->getType());
			para1.push_back(tmp1);
			para1.push_back(var);
			cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para1);
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = tmp1;
            break;
        case PREINC:
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = var;
            break;
        case PREDEC:
			tmp2 = cfg->create_new_tempvar(this->getType());
            para2.push_back(tmp2);
            para2.push_back(var);
			para2.push_back(tmp);
            cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),para2);
            para3.push_back(var);
			para3.push_back(tmp2);
            cfg->current_bb->add_IRInstr(IRInstr::copy,this->getType(),para3);
			returnStr = var;
            break; 
		default:
	    	break;  
    }
    return returnStr;
}

string ExprAssign::buildIR(CFG * cfg){
    //Declaration
    cout << "qsdqsdqsdqsd" << endl;
    string left = myVar->buildIR(cfg);
	Type typeLeft = cfg->get_var_type(left);
	this->setType(typeLeft);
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
    	cout << "qsdqsd" << endl;
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
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(right);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,myVar->getType(),params3);
    }
    return right;
}

string ExprMultAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
	string var3;
	Type* grandType = nullptr;
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
		if(myVar->getType().getTypeValue() > myExpr->getType().getTypeValue()){
			grandType = new Type(myVar->getType().getText());
			string var = cfg->create_new_tempvar(*grandType);
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
			vector<string> params3;
		    params3.push_back(varTemp);
		    params3.push_back(left);
		    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
			//Multiplication
			var3 = cfg->create_new_tempvar(*grandType);
			vector<string> params;
			params.push_back(var3);
			params.push_back(var);
			params.push_back(right);
			cfg->current_bb->add_IRInstr(IRInstr::mul,*grandType,params);
		}else if(myVar->getType().getTypeValue() < myExpr->getType().getTypeValue()){
			grandType = new Type(myExpr->getType().getText());
			string var = cfg->create_new_tempvar(*grandType);
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
			vector<string> params3;
		    params3.push_back(varTemp);
		    params3.push_back(right);
		    cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(right),params3);
			//Multiplication
			var3 = cfg->create_new_tempvar(*grandType);
			vector<string> params;
			params.push_back(var3);
			params.push_back(left);
			params.push_back(var);
			cfg->current_bb->add_IRInstr(IRInstr::mul,*grandType,params);
		}else{
			//Multiplication
			var3 = cfg->create_new_tempvar(this->getType());
			vector<string> params;
			params.push_back(var3);
			params.push_back(left);
			params.push_back(right);
			cfg->current_bb->add_IRInstr(IRInstr::mul,cfg->get_var_type(left),params);
		}
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,myVar->getType(),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,myVar->getType(),params3);
    }
    return right;
}

string ExprDivAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Division
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::div,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprAddAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Addition
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::add,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprSubAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Subtraction
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::sub,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprModAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Subtraction
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::mod,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprAndBinAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Subtraction
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::and_bin,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprOuExBinAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Subtraction
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::ou_ex_bin,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprOuBinAssign::buildIR(CFG * cfg){
    //Declaration
    string left = myVar->buildIR(cfg);
    this->setType(cfg->get_var_type(left));
    //rvalue
    string right = myExpr->buildIR(cfg);
    //Subtraction
    string var3 = cfg->create_new_tempvar(this->getType());
    vector<string> params;
    params.push_back(var3);
    params.push_back(left);
    params.push_back(right);
    cfg->current_bb->add_IRInstr(IRInstr::ou_bin,this->getType(),params);
    //Get the address of the variable
    if(dynamic_cast<ElemLv*>(myVar) == nullptr) {
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
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }else{
        //Assignment
        vector<string> params3;
        params3.push_back(left);//Here, we use the value in var
        params3.push_back(var3);
        cfg->current_bb->add_IRInstr(IRInstr::wmem,cfg->get_var_type(left),params3);
    }
    return right;
}

string ExprSizeOf::buildIR(CFG * cfg){
    Type typeInt("int");
    string var = cfg->create_new_tempvar(typeInt);
    if(evType != ""){
	int size;
	if(evType == "int"){
	    size = 8;
	}else if(evType == "char"){
	    size = 1;
	}
	vector<string> params;
	params.push_back(var);
	params.push_back(to_string(size));
	cfg->current_bb->add_IRInstr(IRInstr::ldconst,typeInt,params);
    }else{
	string varName = myVar->buildIR(cfg);
    }
    return var;
}
