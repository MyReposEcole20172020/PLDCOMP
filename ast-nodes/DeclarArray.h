#pragma once
#include <string>
#include <vector>
#include "Type.h"
#include "Statement.h"
using namespace std;

/*Node which represents a declaration of an array*/

class DeclarArray : public Statement{
   public:
		DeclarArray(string oneName, string oneType, string oneInt) : myName(oneName),size(stoi(oneInt)){myType = new Type(oneType); }
		~DeclarArray();
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
      
    protected:
        string myName;
		Type* myType;
		int size;
};
