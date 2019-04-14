#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "DefFunc.h"
#include "DecFunc.h"
#include "Include.h"
using namespace std;

/*Node which represents a program*/

class Program{
    public:
        Program();
        virtual ~Program();
        void addFunction(Function* func){
            funcs.push_back(func);
        }
	void addInclude(Include* inc){
            incs.push_back(inc);
        }
	    /*Creates the correspondant IR instruction of this node in CFG*/
        string buildIR();
        void generateCode(ofstream& o);
	void verifierRedefinition();
	void verifierDeclarations();
	void verifierDeclaration(Function* func);
	    Type* getFuncReturn(string name);
            
    protected:
        vector<Function*> funcs;
	vector<Include*> incs;
        vector<CFG*> cfgs;
};
