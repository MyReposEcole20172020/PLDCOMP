#pragma once
#include <vector>
#include "Statement.h"
#include <fstream>
#include <unordered_map>

using namespace std;

enum SYMBOL_STAT {
	NON_DECLARED,
	NON_DEFINED,
	PART_DEFINED,
	DEFINED
};


/*Node which represents a block containing a sequence of statements*/
class Block{


	public:
		Block(): parentBlock(nullptr) { }
		virtual ~Block();
		void addStatement(Statement* stat){
			stats.push_back(stat);
		}
		/*Creates the correspondant IR instruction of this node in CFG*/
		string buildIR(CFG* cfg);

		//void parentBlock(Block *);
		
		SYMBOL_STAT getSymbolStat(string symbolName);
		void changeSymbolStat(string symbolName, SYMBOL_STAT stat);
		void setParentBlock(Block * block);
		void addChildBlock(Block * block);
      
    protected:
       	vector<Statement*> stats;

	   	unordered_map<string, SYMBOL_STAT> symbolStat;
	   	vector<Block *> childrenBlocks;
		Block * parentBlock;
};

