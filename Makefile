ANTLR=/shares/public/tp/antlr/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP
compilateur=./Main.exe
default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  Main.g4
	clang++ -DTRACE -g -std=c++11  -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp ./gen-assembly/*.cpp ./ast-nodes/*.cpp  -o $(compilateur) $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
clean:
	rm -rf MainBaseVisitor.* MainLexer.* MainParser.* MainVisitor.* *.dot *.pdf *.interp *.tokens *.exe *.s *.o *.out

build:
	@$(compilateur) $(file).c
	@as -o $(file).o $(file).s
	@gcc -Wfatal-errors $(file).o

BackEnd:
	#@mkdir -p ./tests/testsBackEnd/results
	#@mkdir -p $(folderOutput)
	#@./Main.exe $(folderC)/$(file).c $(file) $(folderC) $(folderO) $(folderOutput)
	#@as -o $(folderO)/$(file).o $(folderO)/$(file).s
	#gcc $(folderO)/$(file).o -o $(folderO)/$(file).out2
bc:
	#@rm -rf ./tests/testsBackEnd/results
	rm -rf *.s *.o *.out *.dot *.pdf
FrontEnd:
	@mkdir -p $(folderC)/results/$(file) 
	@./Main.exe $(folderC)/$(file).c $(file) $(folderC) $(folderO) $(folderOutput)
FrontEndAS:
	@as -o $(folderO)/$(file).o $(folderO)/$(file).s
FrontClean:
	rm -rf ./tests/testsFrontEnd/ValidPrograms/results ./tests/testsFrontEnd/SyntaxError/results ./tests/testsFrontEnd/SemanticError/results ./tests/testsFrontEnd/LexError/results
