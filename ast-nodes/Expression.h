#pragma once
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Type.h"
using namespace std;

class CFG;

enum OPTYPE{
  ADD,SUB,MULT,DIV,MOD,ANDBIN,OUEXBIN,OUBIN,POSTINC,POSTDEC,PREINC,PREDEC,GREAT,LESS,GREATEQ,LESSEQ,EQUAL,UNEQUAL
};

const string opNames[21] = {"+","-","*","/","%","&","^","|","++","--","++","--",">","<",">=","<=","==","!="};

/*Node which represents the operator of binary expression*/

/*Node which represents the operator of binary expression*/

/*Node which represents the operator of binary expression*/

/*Node which represents the operator of binary expression*/

class Operator{
	public:
		Operator(OPTYPE oneValue) : value(oneValue) { }
			virtual ~Operator(){}
		string getName(){
			return opNames[value];
		}
		OPTYPE getValue(){
			return value;
		}
    protected:
		OPTYPE value;
};

/*Node which represents an expression*/

class Expr {
   public:
		Expr() : type("unknown") { }
		virtual ~Expr(){}
		virtual int eval () = 0;
		/*Creates the correspondant IR instruction of this node in CFG*/
		virtual string buildIR(CFG * cfg) = 0;
		virtual Type getType(){
			return type;
		}
		void setType(Type oneType){
			type = oneType;
		}
    protected:
		Type type;
};

class ExprInt : public Expr {
    public:
		ExprInt(int oneValue) : value(oneValue) { type=Type("int"); }
		virtual ~ExprInt(){}
		int eval (){
			return value;
		}
		string buildIR(CFG * cfg);
    protected:
		int value;
};

class ExprVar : public Expr {
    public:
		ExprVar(string oneName) : myName(oneName) {type=Type("unknown"); }
		virtual ~ExprVar(){}
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		string myName;
};

class ExprChar : public Expr {
    public:
		ExprChar(char oneChar) : value(oneChar) {type=Type("char"); }
		virtual ~ExprChar(){}
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		char value;
};

class ExprBinary : public Expr {
    public:
		ExprBinary(OPTYPE oneType, Expr* oneOp1, Expr* oneOp2) : op1(oneOp1), op2(oneOp2){ myOp = new Operator(oneType); type=Type("int");}
		virtual ~ExprBinary(){ delete op1; delete op2; delete myOp; }
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		Expr* op1;
		Expr* op2;
		Operator* myOp;
};

class ExprUnary : public Expr {
    public:
		ExprUnary(OPTYPE oneType, Expr* oneOp) : op(oneOp){ myOp = new Operator(oneType); type=Type("int");}
		virtual ~ExprUnary(){ delete op;delete myOp; }
		int eval (){
			return 0;
		}
		string buildIR(CFG * cfg);
    protected:
		Expr* op;
		Operator* myOp;
};

class ExprAssign : public Expr {
    public:
		ExprAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprMultAssign : public Expr {
    public:
		ExprMultAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprMultAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprDivAssign : public Expr {
    public:
		ExprDivAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprDivAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprAddAssign : public Expr {
    public:
		ExprAddAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprAddAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprSubAssign : public Expr {
    public:
		ExprSubAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprSubAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprModAssign : public Expr {
    public:
		ExprModAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprModAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprAndBinAssign : public Expr {
    public:
		ExprAndBinAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprAndBinAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprOuExBinAssign : public Expr {
    public:
		ExprOuExBinAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprOuExBinAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprOuBinAssign : public Expr {
    public:
		ExprOuBinAssign(string oneName, Expr* oneExpr ) : myExpr(oneExpr){ myVar = new ExprVar(oneName); type = Type("unknown");}
		int eval (){
			return 0;
		}
		virtual ~ExprOuBinAssign(){delete myExpr; delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		Expr* myExpr; 
};

class ExprSizeOf : public Expr {
    public:
		ExprSizeOf(string oneType, string varName ) {type = Type("unknown"); myVar = new ExprVar(varName); evalType = oneType;}
		int eval (){
			return 0;
		}
		virtual ~ExprSizeOf(){delete myVar;}
		string buildIR(CFG * cfg);
	protected:
		ExprVar* myVar;
		string evalType; 
};
