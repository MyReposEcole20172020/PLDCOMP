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
		o << "	movl  ";
		o << "$" << c;
    	o << "," << offset <<"(%rbp)\n";
	}else if(t.getText() == "int64_t"){
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
		o << "	movl  ";
		o << offsetS <<"(%rbp)";
    	o << "," << "%eax\n";
		o << "	movl  ";
		o << "%eax";
    	o << "," << offsetD <<"(%rbp)\n";
		o << "\n";
	}else if(t.getText() == "int64_t"){
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
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}else if(t.getText() == "char"){
			o << "	movb  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}else if(t.getText() == "char"){
			o << ", %dl\n";
		}
	}
	
	if(y == "!bp"){
		o << "	addq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	addl  ";
		}else if(t.getText() == "int64_t"){
			o << "	addq  ";
		}else if(t.getText() == "char"){
			o << "	addb  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}else if(t.getText() == "char"){
			o << ", %dl\n";
		}
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}else if(t.getText() == "char"){
			o << "	movb  ";
			o << "%dl, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void SubInstr::gen_asm(ostream &o) {
	int offset;
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}else if(t.getText() == "char"){
			o << "	movb  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}else if(t.getText() == "char"){
			o << ", %dl\n";
		}
	}
	
	if(y == "!bp"){
		o << "	subq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	subl  ";
		}else if(t.getText() == "int64_t"){
			o << "	subq  ";
		}else if(t.getText() == "char"){
			o << "	subb  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}else if(t.getText() == "char"){
			o << ", %dl\n";
		}
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}else if(t.getText() == "char"){
			o << "	movb  ";
			o << "%dl, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void MulInstr::gen_asm(ostream &o) {
	int offset;
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	
	if(y == "!bp"){
		o << "%rbp\n";
		o << "	mulq  ";
	}else{
		if(t.getText() == "int"){
			o << "	mull  ";
		}else if(t.getText() == "int64_t"){
			o << "	mulq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)\n";
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void DivInstr::gen_asm(ostream &o) {
	int offset;
	o <<"	movq  $0, %rdx\n";
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	/*o <<"	cltd\n";*/
	//o <<"	cqto\n";
	o <<"	cltq\n";
	
	if(y == "!bp"){
		o << "	divq  ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	divl  ";
		}else if(t.getText() == "int64_t"){
			o << "	divq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)\n";
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void ModInstr::gen_asm(ostream &o) {
	int offset;
	o <<"	movq  $0, %rdx\n";
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	/*o <<"	cltd\n";*/
	//o <<"	cqto\n";
	o <<"	cltq\n";
	
	if(y == "!bp"){
		o << "	divq  ";
		o << "%rbp";
	}else{
		if(t.getText() == "int"){
			o << "	divl  ";
		}else if(t.getText() == "int64_t"){
			o << "	divq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
	}
	o <<"\n";
	
		
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rdx, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%edx, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rdx, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void AndBinInstr::gen_asm(ostream &o) {
	int offset;
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
		
	if(y == "!bp"){
		o << "	andq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	andl  ";
		}else if(t.getText() == "int64_t"){
			o << "	andq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void OuExBinInstr::gen_asm(ostream &o) {
	int offset;
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	
	if(y == "!bp"){
		o << "	xorq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	xorl  ";
		}else if(t.getText() == "int64_t"){
			o << "	xorq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void OuBinInstr::gen_asm(ostream &o) {
	int offset;
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	if(y == "!bp"){
		o << "	orq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	orl  ";
		}else if(t.getText() == "int64_t"){
			o << "	orq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "%rax, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "%eax, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "%rax, ";
		}
		offset = bb->get_cfg()->get_var_index(dest);
		o << offset << "(%rbp)\n";
	}
}

void CmpInstr::gen_asm(ostream &o) {
    int offset;
		
	if(x == "!bp"){
		o << "	movq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
		}
		offset = bb->get_cfg()->get_var_index(x);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
		
		
	if(y == "!bp"){
		o << "	cmpq  ";
		o << "%rbp";
		o << ", %rax\n";
	}else{
		if(t.getText() == "int"){
			o << "	cmpl  ";
		}else if(t.getText() == "int64_t"){
			o << "	cmpq  ";
		}
		offset = bb->get_cfg()->get_var_index(y);
		o << offset << "(%rbp)";
		if(t.getText() == "int"){
			o << ", %eax\n";
		}else if(t.getText() == "int64_t"){
			o << ", %rax\n";
		}
	}
		
	switch(op) {
	    case cmp_eq:
	        o << "	sete  %cl \n";
	        break;
	    case cmp_neq:
	        o << "	setne  %cl \n";
	        break;
	    case cmp_lt : 
	        o << "	setl  %cl \n";
	        break;
	    case cmp_le : 
	        o << "	setle  %cl \n";
	        break;
	    default :
	        break;
	}
	o << "	andb  $1, %cl \n";
	
	if(dest == "!bp"){
		o << "	movq  ";
		o << "$0, ";
		o << "%rbp\n";
	}else{
		if(t.getText() == "int"){
			o << "	movl  ";
			o << "$0, ";
		}else if(t.getText() == "int64_t"){
			o << "	movq  ";
			o << "$0, ";
		}
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
    if(this->t.getText() == "char") {
        o << "movq    $0, %rax\n";
	}
	for(int i =0; i<params.size(); ++i) {
	    offset = bb->get_cfg()->get_var_index(params[i]);
	    o << "	movq    ";
	    o << offset << "(%rbp), ";
	    o << "%" << ParamRegister[i] << "\n";
	}
	o << "	call " << label << "@PLT" << "\n";
	if(dest != ""){
	    offset = bb->get_cfg()->get_var_index(dest);
	    if(this->t.getText() == "char") {
	        o << "	movb    ";
	        o << "%al, ";
	    } else if (this->t.getText() == "int") {
	    	o << "	movl    ";
	        o << "%eax, ";
	    }else {
	        o << "	movq    ";
	        o << "%rax, ";
	    }
	    o << offset << "(%rbp)\n ";
	}
}

void WmemInstr::gen_asm(ostream &o) {
	int offset = bb->get_cfg()->get_var_index(dest);
	if(t.getText() == "int"){
		o << "	movq  ";
		o << offset <<"(%rbp), %rax\n";	
		offset = bb->get_cfg()->get_var_index(val);
		o << "	movl  ";
		o << offset <<"(%rbp), %r10d\n";	
		o << "	movl  ";
		o << "%r10d, (%rax)\n";	
	}else if(t.getText() == "int64_t"){
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
		o << "	movl  ";	
		o << "(%rax), %r10d\n";	
		offset = bb->get_cfg()->get_var_index(dest);
		o << "	movl  ";
		o << "%r10d, "<< offset <<"(%rbp)\n";	
	}else if(t.getText() == "int64_t"){
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
