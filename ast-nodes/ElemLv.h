#pragma once
#include <vector>
#include "Expression.h"
using namespace std;

/*Node which represents a call of function*/

class ElemLv : public Expr{
	public:
		ElemLv(string oneName, Expr* oneExpr) : arrayName(oneName), myExpr(oneExpr) { type=Type("unknown"); }
		virtual ~ElemLv();
		void evalType() {}
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);
      
	protected:
	    string arrayName;
		Expr* myExpr;
};
