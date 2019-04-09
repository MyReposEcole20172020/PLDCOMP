.text 
	.globl	main
main:
.PROLOGmain : 
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $48,   %rsp

.main : 
	movl  $10,-24(%rbp)
	movl  $-16,-32(%rbp)
	movq  %rbp, %rax
	addl  -32(%rbp), %eax
	movl  %eax, -32(%rbp)
	movq  -32(%rbp), %rax
	movl  -24(%rbp), %r10d
	movl  %r10d, (%rax)
	movl  $-8,-40(%rbp)
	movq  %rbp, %rax
	addl  -40(%rbp), %eax
	movl  %eax, -40(%rbp)
	movq  -40(%rbp), %rax
	movl  -16(%rbp), %r10d
	movl  %r10d, (%rax)
	jmp  .EPILOGmain 
.LBB_main_1 : 
	jmp  .EPILOGmain 
.EPILOGmain : 
	movq  -8(%rbp), %rax
	addq    $48,   %rsp
	popq   %rbp
	retq
