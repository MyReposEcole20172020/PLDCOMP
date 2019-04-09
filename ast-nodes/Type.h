#pragma once
#include <string>

using namespace std;

enum ENUMTYPE{
    VOID,
    CHAR,
    INT,
	INT64_T,
    CHARPOINTER,
	INTPOINTER,
	INT64_TPOINTER,
    UNKNOWN
};

const string typeLabel[] = {"void","char","int","int64_t","char*","int*","int64_t*","unknown"};

/*Node which represents the type of variable or return*/

class Type{
   public:
      Type(string oneType);
      virtual ~Type(){}
      string getText();
	  int getTypeValue(){
		return (int)myType;
	  }
    protected:
        ENUMTYPE myType;

};
