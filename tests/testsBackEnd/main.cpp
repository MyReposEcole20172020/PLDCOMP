#include <iostream>
#include "antlr4-runtime.h"
#include "MainLexer.h"
#include "MainParser.h"
#include "Comp.h"
#include "MainBaseVisitor.h"
#include "dotexport.h"
#include <string>
#include <vector>

using namespace antlr4;
using namespace std;

/*Main file which lauchs the compilation*/

int testUnitaire(const char ** argv){
	//Main.exe test.c 
	ifstream is (argv[1]);
	if (!is){
        cout << "erreur ouverture fichier" << endl;
        return -1;
    }
	string fileC(argv[1]);
	size_t pos=fileC.find_last_of(".c");
	string file=fileC.substr(0,pos-1);
	
    ANTLRInputStream input(is);
	MainLexer lexer(&input);


	CommonTokenStream tokens(&lexer);
	MainParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();
	if(parser.getNumberOfSyntaxErrors()!=0){
		cout<<"Syntax Error"<<endl;	
		return 0;
	}	
	DotExport dotexport(&parser);
	tree::ParseTreeWalker::DEFAULT.walk(&dotexport,tree);

	ofstream out;
	out.open("tmp.dot");
	out<<dotexport.getDotFile();
	out.close();
	string cmd="dot -Tpdf -o out.pdf tmp.dot";
	system(cmd.c_str());

	Comp visitor;
	Program* prog = (Program*)visitor.visit(tree);
	prog->buildIR();
	ofstream o;
	o.open(file+".s");
	prog->generateCode(o);
	return 0;
}

int testMultiple(const char ** argv){
	// Main.exe 
ifstream is (argv[1]);

    if (!is){
        cout << "erreur ouverture fichier" << endl;
        return -1;
    }
	string file(argv[2]);
	string folderC(argv[3]);
	string folderO(argv[4]);
	string folderOutput(argv[5]);
	
    ANTLRInputStream input(is);
	MainLexer lexer(&input);


	CommonTokenStream tokens(&lexer);
	MainParser parser(&tokens);
	tree::ParseTree* tree = parser.prog();
	if(parser.getNumberOfSyntaxErrors()!=0){
		cout<<"Syntax Error"<<endl;	
		return 0;
	}	
	DotExport dotexport(&parser);
	tree::ParseTreeWalker::DEFAULT.walk(&dotexport,tree);

	ofstream out;
	out.open(folderO+"/tmp.dot");
	out<<dotexport.getDotFile();
	out.close();
	string outPDF=folderO+"/out.pdf";
	string tmpDOT=folderO+"/tmp.dot";
	string cmd="dot -Tpdf -o "+outPDF+" "+tmpDOT;
	system(cmd.c_str());

	Comp visitor;
	Program* prog = (Program*)visitor.visit(tree);
	prog->buildIR();
	ofstream o;
	o.open(folderO+"/"+file+".s");
	prog->generateCode(o);
	return 0;
}





int main(int argc, const char ** argv) 
{
	if (argc == 2 ){
		testUnitaire(argv);
	}
	else if (argc > 2){
		testMultiple(argv);
	}
	else{
		cout <<"parametre manquant"<<endl;
	}
	return 0;
}
