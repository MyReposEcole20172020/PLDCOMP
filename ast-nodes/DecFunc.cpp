#include "DecFunc.h"


DecFunc::~DecFunc() { 
    /*size_t length = params.size();
    for(size_t i = 0; i < length; i++){
        delete params[i];
    }
    params.clear();*/
    if(decParams != nullptr){
	    delete decParams;
    }
    delete returnType;
}

string DecFunc::buildIR(CFG* cfg){
    return "";
}
