#include "Type.h"

Type::Type(string oneType){
    if(oneType == "int"){
        myType = INT;
    }else if(oneType == "void"){
        myType = VOID;
    }else if(oneType == "char"){
        myType = CHAR;
    }else if(oneType == "int64_t"){
        myType = CHAR;
    }else if(oneType == "int*"){
        myType = INTPOINTER;
    }else if(oneType == "char*"){
        myType = CHARPOINTER;
    }else if(oneType == "int64_t*"){
        myType = CHARPOINTER;
    }else{
        myType = UNKNOWN;
    }
}

string Type::getText(){
    return typeLabel[myType];
}
