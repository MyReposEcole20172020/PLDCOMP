#include <iostream>
#include "antlr4-runtime.h"
#include "MainLexer.h"
#include "MainParser.h"
#include "Comp.h"
#include "MainBaseVisitor.h"
#include "dotexport.h"
#include <string>
#include <vector>
#include <cstdlib>

using namespace antlr4;
using namespace std;

/*Main file which lauchs the compilation*/

void testUnit(const char ** argv){
	ifstream is (argv[1]);
	if (!is){
		cout << "erreur ouverture fichier" << endl;
		exit(0);
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
		exit(0);
	}	
	DotExport dotexport(&parser);
	tree::ParseTreeWalker::DEFAULT.walk(&dotexport,tree);

	//ofstream out;
	//out.open("tmp.dot");
	//out<<dotexport.getDotFile();
	//out.close();
	//string cmd="dot -Tpdf -o out.pdf tmp.dot";
	//system(cmd.c_str());

	Comp visitor;
	Program* prog = (Program*)visitor.visit(tree);
	prog->buildIR();
	ofstream o;
	o.open(file+".s");
	prog->generateCode(o);
}

void testWithoutParameter(){
	cout<<"Welcome to discovery our compilator!"<<endl;
	cout<<"1.All the tests"<<endl;
	cout<<"2.One test"<<endl;
	cout<<"3.Quit"<<endl;
	int choice;
	cout<<"Please choose 1 or 2 or 3: "<<endl;
	cin>>choice;
	int flag=1;
	while (choice!=3 || flag!=0 ){
		if(choice==1){
			system("sh test.sh");
			cout<<"1.All the tests"<<endl;
			cout<<"2.One test"<<endl;
			cout<<"3.Quit"<<endl;
			cout<<"Please choose 1 or 2 or 3: "<<endl;
			cin>>choice;
		}
		else if(choice==2){
			cout<<"Please enter the file to compile with relative path:"<<endl;
			string cmd;
			string filename;
			cin>>filename;
			cout<<endl;
			cmd="make --no-print-directory testUnit fileC="+filename;
			system(cmd.c_str());
			cout<<"1.All the tests"<<endl;
			cout<<"2.One test"<<endl;
			cout<<"3.Quit"<<endl;
			cout<<"Please choose 1 or 2 or 3: "<<endl;
			cin>>choice;
		}
		else if (choice==3){
			cout<<"Thank you for enjoying our game of tests, goodbye!"<<endl;
			flag=0;
		}
		else{
			cout<<"Please retry to choose!"<<endl;
			cout<<"1.All the tests"<<endl;
			cout<<"2.One test"<<endl;
			cout<<"3.Quit"<<endl;
			cout<<"Please choose 1 or 2 or 3: "<<endl;
			cin>>choice;
		}	
	}
}

int main(int argc, const char ** argv) 
{
	if (argc == 2 ){
		testUnit(argv);
	}
	else if (argc == 1 ){
		testWithoutParameter();	
	}
	else{
		cerr<<"We need at least one parameter! "<<endl;
	}
	return 0;
}
