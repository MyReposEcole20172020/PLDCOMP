#include "Block.h"

Block::~Block() { 
    size_t length = stats.size();
    for(size_t i = 0; i < length; i++){
        delete stats[i];
    }
    stats.clear();
}

string Block::buildIR(CFG* cfg){
	//cfg->add_currentBlockDepth();	
    for(Statement* stat : stats){
        stat->buildIR(cfg);
    }
    //cfg->sub_currentBlockDepth();	
    return "";
}

/*void Block::addStatement(Statement* stat){
    stats.push_back(stat);
}*/
