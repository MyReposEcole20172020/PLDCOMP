#pragma once
#include <string>
#include "Expression.h"
#include "Block.h"
using namespace std;

/*Node which represents a elseif in statement*/

class ElseIf {
    public:
        ElseIf(Expr* oneExpr, Block* oneBlock) : myCondition(oneExpr), myBlock(oneBlock){}
		ElseIf(Expr* oneExpr, Statement* oneStatement);
        virtual ~ElseIf();
		Expr* getMyCondition(){return myCondition;}
		Block* getMyBlock(){return myBlock;}
    protected:
        Expr* myCondition;
		Block * myBlock;
};
