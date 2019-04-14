#include "If.h"

If::If(Expr* oneExpr, Statement* oneStatement) : myCondition(oneExpr)
{
	myBlock = new Block;
	myBlock->addStatement(oneStatement);
	myElse = nullptr;
}

If::~If()
{
	if(myBlock != nullptr){
		delete myBlock;
	}
	if(myElse != nullptr){
		delete myElse;
	}
	for(ElseIf* e : myElseIfs){
		delete e;
	}
	delete myCondition;
}

string If::buildIR(CFG* cfg){
    if(myElseIfs.size() == 0){
	string var = myCondition->buildIR(cfg);
	if(dynamic_cast<ExprVar*>(myCondition) != nullptr) {
		vector<string> params3;
        params3.push_back(var);
        params3.push_back(var);
        cfg->current_bb->add_IRInstr(IRInstr::copy,myCondition->getType(),params3);
	}
	BasicBlock* testBB = cfg->current_bb;
	BasicBlock* thenBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(thenBB);
	BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(afterIfBB);
	if(myElse != nullptr){
	    BasicBlock* elseBB = new BasicBlock(cfg, cfg->new_BB_name());
	    cfg->add_bb(elseBB);	
	    afterIfBB->set_exit_true(testBB->get_exit_true());
	    afterIfBB->set_exit_false(testBB->get_exit_false());
	    testBB->set_exit_true(thenBB);
	    testBB->set_exit_false(elseBB);
	    thenBB->set_exit_true(afterIfBB);
	    thenBB->set_exit_false(nullptr);
	    elseBB->set_exit_true(afterIfBB);
	    elseBB->set_exit_false(nullptr);
	    cfg->current_bb = elseBB;
	    myElse->buildIR(cfg);
	}else{
	    afterIfBB->set_exit_true(testBB->get_exit_true());
	    afterIfBB->set_exit_false(testBB->get_exit_false());
	    testBB->set_exit_true(thenBB);
	    testBB->set_exit_false(afterIfBB);
	    thenBB->set_exit_true(afterIfBB);
	    thenBB->set_exit_false(nullptr);
	}
	cfg->current_bb = thenBB;
	myBlock->buildIR(cfg);
	cfg->current_bb = afterIfBB;
    }else{
	string var = myCondition->buildIR(cfg);
	if(dynamic_cast<ExprVar*>(myCondition) != nullptr) {
		vector<string> params3;
        	params3.push_back(var);
        	params3.push_back(var);
        	cfg->current_bb->add_IRInstr(IRInstr::copy,myCondition->getType(),params3);
		//cout << "in" << endl;
	}
	BasicBlock* testBB = cfg->current_bb;
	BasicBlock* thenBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(thenBB);
	BasicBlock* afterIfBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(afterIfBB);
	BasicBlock* firstElseIfBB = new BasicBlock(cfg, cfg->new_BB_name());
	cfg->add_bb(firstElseIfBB);
	afterIfBB->set_exit_true(testBB->get_exit_true());
	afterIfBB->set_exit_false(testBB->get_exit_false());
	testBB->set_exit_true(thenBB);
	testBB->set_exit_false(firstElseIfBB);
	thenBB->set_exit_true(afterIfBB);
	thenBB->set_exit_false(nullptr);
	vector<BasicBlock*> elseCondBB;
	vector<BasicBlock*> elseBlockBB;
	BasicBlock* oldCondBB = firstElseIfBB;
	elseCondBB.push_back(firstElseIfBB);
	size_t length = myElseIfs.size();
	for(size_t i = 0; i < length-1; i++){
		BasicBlock* tempBlock = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(tempBlock);
		elseBlockBB.push_back(tempBlock);
		BasicBlock* tempCond = new BasicBlock(cfg, cfg->new_BB_name());
		cfg->add_bb(tempCond);
		elseCondBB.push_back(tempCond);
		oldCondBB->set_exit_true(tempBlock);
		oldCondBB->set_exit_false(tempCond);
		tempBlock->set_exit_true(afterIfBB);
		tempBlock->set_exit_false(nullptr);
		oldCondBB = tempCond;
	}
	if(myElse != nullptr){
	    BasicBlock* lastBB = new BasicBlock(cfg, cfg->new_BB_name());
	    cfg->add_bb(lastBB);
	    elseBlockBB.push_back(lastBB);
	    BasicBlock* elseBB = new BasicBlock(cfg, cfg->new_BB_name());
	    cfg->add_bb(elseBB);
	    oldCondBB->set_exit_true(lastBB);
	    oldCondBB->set_exit_false(elseBB);
	    lastBB->set_exit_true(afterIfBB);
	    lastBB->set_exit_false(nullptr);
	    elseBB->set_exit_true(afterIfBB);
	    elseBB->set_exit_false(nullptr);
	    cfg->current_bb = elseBB;
	    myElse->buildIR(cfg);
	}else{
	    BasicBlock* lastBB = new BasicBlock(cfg, cfg->new_BB_name());
	    cfg->add_bb(lastBB);
	    elseBlockBB.push_back(lastBB);
	    oldCondBB->set_exit_true(lastBB);
	    oldCondBB->set_exit_false(afterIfBB);
	    lastBB->set_exit_true(afterIfBB);
	    lastBB->set_exit_false(nullptr);
	}
	cfg->current_bb = thenBB;
	myBlock->buildIR(cfg);
	for(size_t i = 0; i < length; i++){
		Expr* exp = myElseIfs.at(i)->getMyCondition();
		cfg->current_bb = elseCondBB.at(i);
		exp->buildIR(cfg);
		Block* block = myElseIfs.at(i)->getMyBlock();
		cfg->current_bb = elseBlockBB.at(i);
		block->buildIR(cfg);
	}
	cfg->current_bb = afterIfBB;
	//cout << cfg->current_bb << endl;
    }
    return "";
}
