#pragma once
#include <string>
#include "Statement.h"
#include "Expression.h"
#include "Block.h"
#include "Else.h"
#include "ElseIf.h"
using namespace std;


class If : public Statement {
    public:
        If(Expr* oneExpr, Block* oneBlock) : myCondition(oneExpr), myBlock(oneBlock){myElse = nullptr;}
		If(Expr* oneExpr, Statement* oneStatement);
		void addElse(Else* oneElse){myElse = oneElse;}
		void addElseIf(ElseIf* oneElseIf){myElseIfs.push_back(oneElseIf);}
        virtual ~If();

	/*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR(CFG* cfg);
    protected:
        Expr* myCondition;
		Block * myBlock;
		vector<ElseIf*> myElseIfs;
		Else* myElse;
};
