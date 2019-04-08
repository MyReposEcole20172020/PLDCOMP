#include "ElseIf.h"

ElseIf::ElseIf(Expr* oneExpr, Statement* oneStatement) : myCondition(oneExpr)
{
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
}

ElseIf::~ElseIf()
{
	if(myBlock != nullptr){
		delete myBlock;
	}
	delete myCondition;
}
