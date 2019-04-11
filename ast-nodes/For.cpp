#include "For.h"

For::For(Statement* oneInit, Expr* oneExpr, Statement* oneStatement, Statement* afterFor) : myCondition(oneExpr), after(afterFor)
{
	init = oneInit;
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
	//myBlock->addStatement(afterFor);
}

For::~For()
{
	if(myBlock != nullptr){
		delete myBlock;
	}
	delete myCondition;
}

string For::buildIR(CFG* cfg){
	init->buildIR(cfg);
	BasicBlock* beforeWhileBB = cfg->current_bb;
	BasicBlock* testBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(testBB);
	BasicBlock* bodyBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(bodyBB);
	BasicBlock* afterWhileBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(afterWhileBB);
	afterWhileBB->set_exit_true(beforeWhileBB->get_exit_true());
	afterWhileBB->set_exit_false(beforeWhileBB->get_exit_false());
	beforeWhileBB->set_exit_true(testBB);
	beforeWhileBB->set_exit_false(nullptr);
	testBB->set_exit_true(bodyBB);
	testBB->set_exit_false(afterWhileBB);
	bodyBB->set_exit_true(testBB);
	bodyBB->set_exit_false(nullptr);
	cfg->current_bb = testBB;
	string var = myCondition->buildIR(cfg);
	if(dynamic_cast<ExprVar*>(myCondition) != nullptr) {
		vector<string> params3;
        params3.push_back(var);
        params3.push_back(var);
        cfg->current_bb->add_IRInstr(IRInstr::copy,myCondition->getType(),params3);
	}
	cfg->current_bb = bodyBB;
	myBlock->buildIR(cfg);
	after->buildIR(cfg);
	cfg->current_bb = afterWhileBB;
    return "";
}
