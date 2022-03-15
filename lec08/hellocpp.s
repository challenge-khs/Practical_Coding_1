	.file	"hellocpp.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.section	.rodata
.LC0:
	.string	"%d : %lld %llx\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$100, -24(%rbp)
	movl	$200, -20(%rbp)
	movq	$999, -16(%rbp)
	movl	-24(%rbp), %edx
	movq	stdout(%rip), %rax
	leaq	-24(%rbp), %rsi
	leaq	-24(%rbp), %rcx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	-20(%rbp), %edx
	movq	stdout(%rip), %rax
	leaq	-20(%rbp), %rsi
	leaq	-20(%rbp), %rcx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rcx
	leaq	-24(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	add
	movq	-16(%rbp), %rdx
	movq	stdout(%rip), %rax
	leaq	-16(%rbp), %rsi
	leaq	-16(%rbp), %rcx
	movq	%rsi, %r8
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	leaq	-16(%rbp), %rdx
	addq	$8, %rdx
	leaq	-16(%rbp), %rax
	addq	$8, %rax
	movq	-16(%rbp), %rsi
	movq	stdout(%rip), %rdi
	movq	%rdx, %r8
	movq	%rax, %rcx
	movq	%rsi, %rdx
	leaq	.LC0(%rip), %rsi
	movl	$0, %eax
	call	fprintf@PLT
	leaq	-16(%rbp), %rdx
	addq	$16, %rdx
	leaq	-16(%rbp), %rax
	addq	$16, %rax
	movq	-16(%rbp), %rsi
	movq	stdout(%rip), %rdi
	movq	%rdx, %r8
	movq	%rax, %rcx
	movq	%rsi, %rdx
	leaq	.LC0(%rip), %rsi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdi
	xorq	%fs:40, %rdi
	je	.L4
	call	__stack_chk_fail@PLT
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
