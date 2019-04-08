#pragma once
#include <string>

using namespace std;

enum ENUMTYPE{
    VOID,
    INT,
    CHAR,
    INTPOINTER,
    CHARPOINTER,
    UNKNOWN
};

const string typeLabel[6] = {"void","int","char","int*","char*","unknown"};

/*Node which represents the type of variable or return*/

class Type{
   public:
      Type(string oneType);
      virtual ~Type(){}
      string getText();
    protected:
        ENUMTYPE myType;

};
