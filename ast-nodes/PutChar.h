#pragma once
#include <vector>
#include "Statement.h"
#include "Expression.h"
using namespace std;

/*Node which represents a call of function*/

class PutChar : Expr{
	public:
		PutChar(string oneName, Expr* oneExpr) : funcName(oneName), myExpr(oneExpr) { type=Type("unknown"); }
		virtual ~PutChar();
		void evalType() {}
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
      
	protected:
	    string funcName;
		Expr* myExpr;
};
