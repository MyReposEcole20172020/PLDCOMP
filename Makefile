ANTLR=/shares/public/tp/antlr/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP
compilateur=./Main.exe
grammaire=./Main.g4
back=./tests/testsBackEnd
frontError=./tests/testsFrontEnd/ErrorPrograms
frontValid=./tests/testsFrontEnd/ValidPrograms
default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  $(grammaire)
	clang++ -DTRACE -g -std=c++11  -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp ./gen-assembly/*.cpp ./ast-nodes/*.cpp  -o $(compilateur) $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
clean:
	rm -rf MainBaseVisitor.* MainLexer.* MainParser.* MainVisitor.* *.dot *.pdf *.interp *.tokens *.exe *.s *.o *.out

test:
	@$(compilateur)
testUnit:
	@sh testUnit.sh $(fileC)
back:
	@$(compilateur) ./tests/$(file).c
	@as -o ./tests/$(file).o ./tests/$(file).s
	@gcc ./tests/$(file).o -o ./tests/a.out
backUnit:
	@$(compilateur) $(file).c
	@as -o $(file).o $(file).s
	@gcc $(file).o -o $(path)/a.out
frontError:
	@$(compilateur) $(frontError)/$(file).c
	@as -w -o $(frontError)/$(file).o $(frontError)/$(file).s
	@gcc -w $(frontfrontError)/$(file).o -o $(frontError)/a.out
frontValid:
	@$(compilateur) $(frontValid)/$(file).c
	@as -o $(frontValid)/$(file).o $(frontValid)/$(file).s
	@gcc -w $(frontValid)/$(file).o -o $(frontValid)/a.out
testclean:
	rm -rf *.s *.o *.out *.dot *.pdf
build:
	@$(compilateur) $(folderC)/$(file).c 
	@as -o $(folderC)/$(file).o $(folderC)/$(file).s
	@gcc $(folderC)/$(file).o -o $(folderC)/$(file).exe
	@rm $(folderC)/$(file).o
	@rm $(folderC)/$(file).s
