ANTLR=/shares/public/tp/antlr/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP

default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  Main.g4
	clang++ -DTRACE -g -std=c++11  -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp ./gen-assembly/*.cpp ./ast-nodes/*.cpp  -o Main.exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
clean:
	rm -rf MainBaseVisitor.* MainLexer.* MainParser.* MainVisitor.* *.dot *.pdf *.interp *.tokens *.exe *.s *.o *.out

build:
	./Main.exe test.c
	as -o test.o test.s
	gcc test.o

testsBackEnd:
	mkdir -p ./tests/testsBackEnd/results/$(file)/out
	./Main.exe ./tests/testsBackEnd/$(file).c
	as -o ./tests/testsBackEnd/results/$(file)/$(file).o ./tests/testsBackEnd/results/$(file)/$(file).s
	gcc -w ./tests/testsBackEnd/results/$(file)/$(file).o -o ./tests/testsBackEnd/results/$(file)/$(file).out2
