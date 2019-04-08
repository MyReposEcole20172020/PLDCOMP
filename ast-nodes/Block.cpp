#include "Block.h"

Block::~Block() { 
    size_t length = stats.size();
    for(size_t i = 0; i < length; i++){
        delete stats[i];
    }
    stats.clear();
}

string Block::buildIR(CFG* cfg){
    for(Statement* stat : stats){
        stat->buildIR(cfg);
    }
    return "";
}

SYMBOL_STAT Block::getSymbolStat(string symbolName) 
{
    auto it =  symbolStat.find(symbolName);
    if (it !=  symbolStat.end())
    {
        return it->second;
    }
    if (parentBlock != nullptr)
    {
        return parentBlock->getSymbolStat(symbolName);
    }

    return SYMBOL_STAT::NON_DECLARED;
    
}

void Block::changeSymbolStat(string symbolName, SYMBOL_STAT stat)
{
    if(stat == SYMBOL_STAT::DEFINED)
    {
        if(parentBlock != nullptr)
        {
            parentBlock->changeSymbolStat(symbolName,SYMBOL_STAT::PART_DEFINED); 
        }      
    }
    else if (stat == SYMBOL_STAT::PART_DEFINED)
    {
        stat = SYMBOL_STAT::DEFINED;

        for (int i = 0; i < childrenBlocks.size(); i++)
        {
            if(childrenBlocks[i]->getSymbolStat(symbolName) != SYMBOL_STAT::DEFINED)
            {
                stat = SYMBOL_STAT::PART_DEFINED;
                break;
            }
        }
    }
    symbolStat[symbolName] = stat;

}

void Block::setParentBlock(Block * block) 
{
    parentBlock = block;
    if (parentBlock != nullptr)
    {
        parentBlock->addChildBlock(this);
    }
    
}
void Block::addChildBlock(Block * block)
{
    childrenBlocks.push_back(block);
}

/*void Block::addStatement(Statement* stat){
    stats.push_back(stat);
}*/
