.text 
	.globl	main
main:
.PROLOGmain : 
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $60,   %rsp

.main : 
	movl  $0,-12(%rbp)
	movq  $-8,-20(%rbp)
	movq  %rbp, %rax
	addq  -20(%rbp), %rax
	movq  %rax, -20(%rbp)
	movq  -20(%rbp), %rax
	movl  -12(%rbp), %r10d
	movl  %r10d, (%rax)
	jmp  .LBB_main_1 
.LBB_main_1 : 
	movl  $10,-24(%rbp)
	movl  -8(%rbp), %eax
	cmpl  -24(%rbp), %eax
	setl  %cl 
	andb  $1, %cl 
	movl  $0, -28(%rbp)
	movb  %cl, -28(%rbp)
	cmpl   $0, -28(%rbp) 
	je  .LBB_main_3 
	jmp  .LBB_main_2 
.LBB_main_2 : 
	movb  $98,-32(%rbp)
movq    $0, %rax
	movq    -32(%rbp), %rdi
	call putchar@PLT
	movl  $1,-36(%rbp)

	movl  -8(%rbp),%eax
	movl  %eax,-40(%rbp)

	movl  -8(%rbp), %eax
	addl  -36(%rbp), %eax
	movl  %eax, -44(%rbp)

	movl  -44(%rbp),%eax
	movl  %eax,-8(%rbp)

	jmp  .LBB_main_1 
.LBB_main_3 : 
	movq  $-4,-52(%rbp)
	movq  %rbp, %rax
	addq  -52(%rbp), %rax
	movq  %rax, -52(%rbp)
	movq  -52(%rbp), %rax
	movl  -8(%rbp), %r10d
	movl  %r10d, (%rax)
	jmp  .EPILOGmain 
.LBB_main_4 : 
	jmp  .EPILOGmain 
.EPILOGmain : 
	movl  -4(%rbp), %eax
	addq    $60,   %rsp
	popq   %rbp
	retq
