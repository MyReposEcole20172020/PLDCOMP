#include "DeclarArray.h"

DeclarArray::~DeclarArray(){
    delete myType;
}

string DeclarArray::buildIR(CFG* cfg){
    int sizeType;
    Type *pointer = nullptr;
    if(myType->getText() == "int"){
        sizeType = 4;
        pointer = new Type("int*");
    }else if(myType->getText() == "char"){
        sizeType = 4;
        pointer = new Type("char*");
    }else if(myType->getText() == "int64_t"){
        sizeType = 8;
        pointer = new Type("int64_t*");
    }
    int sizeTotal = size*sizeType;
    cfg->add_to_symbol_table(myName,*pointer, sizeTotal);
    vector<string> params;
    params.push_back(myName);
    params.push_back(to_string(-1*cfg->getNextFreeSymbolIndex()));
    cfg->current_bb->add_IRInstr(IRInstr::ldconst,Type("int64_t"),params);
    return myName;
}
