#include "IRInstr.h"
#include "BasicBlock.h"
#include "../ast-nodes/Function.h"
#include "CFG.h"

void RetInstr::gen_asm(ostream &o) {
	/*Type retType = bb->get_cfg()->get_var_type("retValue");
	if(retType.getText()!= "void"){
	    int offsetReturn = bb->get_cfg()->get_var_index("retValue");
	    int offsetValue = bb->get_cfg()->get_var_index(value);
	    if(retType.getText() == "int"){
		    o << "	movl  ";
        	o << offsetValue <<"(%rbp)";
		    o << "," << offsetReturn <<"(%rbp)";
	    }else if(retType.getText() == "char"){
		    o << "	movb  ";
        	o << offsetValue <<"(%rbp)";
		    o << "," << offsetReturn <<"(%rbp)";
	    }
	}*/
}

void LdconstInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(dest);
	if(t.getText() == "int"){
		o << "	movq  ";
		o << "$" << c;
    	o << "," << offset <<"(%rbp)\n";
	}else if(t.getText() == "char"){
		o << "	movb  ";
		o << "$" << c;
    	o << "," << offset <<"(%rbp)\n";
	}	
}

void CopyInstr::gen_asm(ostream &o) {
	int offsetD = bb->get_cfg()->get_var_index(dest);
	int offsetS = bb->get_cfg()->get_var_index(s);
	if(t.getText() == "int"){
		o << "\n";
		o << "	movq  ";
		o << offsetS <<"(%rbp)";
    	o << "," << "%rax\n";
		o << "	movq  ";
		o << "%rax";
    	o << "," << offsetD <<"(%rbp)\n";
		o << "\n";
	}else if(t.getText() == "char"){
		o << "	movb  ";
		o << offsetS <<"(%rbp)";
    	o << "," << "%dl\n";
		o << "	movb  ";
		o << "%dl";
    	o << "," << offsetD <<"(%rbp)\n";
	}	
}

void AddInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	addq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void SubInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	subq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void MulInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	mulq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o << "\n";
	/*o <<", %rax\n";*/
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void DivInstr::gen_asm(ostream &o) {
	int offset;
	o <<"	movq  $0, %rdx\n";
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	/*o <<"	cltd\n";*/
	//o <<"	cqto\n";
	o <<"	cltq\n";
	o << "	divq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<"\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void ModInstr::gen_asm(ostream &o) {
	int offset;
	o <<"	movq  $0, %rdx\n";
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	/*o <<"	cltd\n";*/
	//o <<"	cqto\n";
	o <<"	cltq\n";
	o << "	divq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<"\n";
	
	o << "	movq  ";
	o << "%rdx, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void AndBinInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	andq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void OuExBinInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	xorq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void OuBinInstr::gen_asm(ostream &o) {
	int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	orq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	movq  ";
	o << "%rax, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void CmpInstr::gen_asm(ostream &o) {
    /*movl    $2, %eax
    cmpl    -4(%rbp), %eax
    setle   %cl
    andb    $1, %cl
    movb    %cl, -5(%rbp)*/

    int offset;
	o << "	movq  ";
	if(x == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	
	o << "	cmpq  ";
	if(y == "!bp"){
		o << "%rbp";
	}else{
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<", %rax\n";
	switch(op) {
	    case cmp_eq:
	        o << "        sete  %cl \n";
	        break;
	    case cmp_neq:
	        o << "        setne  %cl \n";
	        break;
	    case cmp_lt : 
	        o << "        setl  %cl \n";
	        break;
	    case cmp_le : 
	        o << "        setle  %cl \n";
	        break;
	    default :
	        break;
	}
	o << "        andb  $1, %cl \n";
	
	o << "	movq  ";
	o << "$0, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
	o << "	movb  ";
	o << "%cl, ";
	if(dest == "!bp"){
		o << "%rbp\n";
	}else{
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void CallInstr::gen_asm(ostream &o) {
	int offset;
	if(params.size() > 6) {
	    cout << "Error";
	}
	for(int i =0; i<params.size(); ++i) {
	    offset = bb->get_cfg()->get_var_index(params[i]);
	    o << "        movq    ";
	    o << offset << "(%rbp), ";
	    o << "%" << ParamRegister[i] << "\n";
	}
	o << "        call " << label << "@PLT" << "\n";
	if(dest != ""){
	    offset = bb->get_cfg()->get_var_index(dest);
	    o << "        movq    ";
	    o << "%rax, ";
	    o << offset << "(%rbp)\n ";
	}
}

void WmemInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(dest);
	if(t.getText() == "int"){
		o << "	movq  ";
		o << offset <<"(%rbp), %rax\n";	
		offset = bb->get_cfg()->get_var_index(val);
		o << "	movq  ";
		o << offset <<"(%rbp), %r10\n";	
		o << "	movq  ";
		o << "%r10, (%rax)\n";	
	}else if(t.getText() == "char"){
		o << "	movq  ";
		o << offset <<"(%rbp), %rax\n";	
		offset = bb->get_cfg()->get_var_index(val);
		o << "	movb  ";
		o << offset <<"(%rbp), %dl\n";	
		o << "	movb  ";
		o << "%dl, (%rax)\n";
	}	
}

void RmemInstr::gen_asm(ostream &o) {
	int offset = 0;
	if(t.getText() == "int"){
		offset = bb->get_cfg()->get_var_index(ad);
		o << "	movq  ";
		o << offset <<"(%rbp) " <<", %rax\n";
		o << "	movq  ";	
		o << "(%rax), %r10\n";	
		offset = bb->get_cfg()->get_var_index(dest);
		o << "	movq  ";
		o << "%r10, "<< offset <<"(%rbp)\n";	
	}else if(t.getText() == "char"){
		offset = bb->get_cfg()->get_var_index(ad);
		o << "	movq  ";
		o << offset <<"(%rbp) " <<", %rax\n";
		o << "	movb  ";	
		o << "(%rax), %dl\n";	
		offset = bb->get_cfg()->get_var_index(dest);
		o << "	movb  ";
		o << "%dl, "<< offset <<"(%rbp)\n";	
	}	
}
