	.file	"Switch_Program.c"
	.text
	.globl	SW_enuInit
	.def	SW_enuInit;	.scl	2;	.type	32;	.endef
	.seh_proc	SW_enuInit
SW_enuInit:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L2
	movb	$0, -5(%rbp)
	movb	$0, -5(%rbp)
	jmp	.L3
.L4:
	movzbl	-5(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %ecx
	movzbl	-5(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$0, %r8d
	movl	%ecx, %edx
	movl	%eax, %ecx
	call	DIO_enuSetPinDirection
	movl	%eax, -4(%rbp)
	movzbl	-5(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	movzbl	%al, %r8d
	movzbl	-5(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %ecx
	movzbl	-5(%rbp), %edx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%ecx, %edx
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	movzbl	-5(%rbp), %eax
	addl	$1, %eax
	movb	%al, -5(%rbp)
.L3:
	cmpb	$2, -5(%rbp)
	jbe	.L4
	jmp	.L5
.L2:
	movl	$2, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	SW_enuGetState
	.def	SW_enuGetState;	.scl	2;	.type	32;	.endef
	.seh_proc	SW_enuGetState
SW_enuGetState:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L8
	cmpq	$0, 24(%rbp)
	je	.L8
	movq	16(%rbp), %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movq	24(%rbp), %rcx
	movq	%rcx, %r8
	movl	%eax, %ecx
	call	DIO_enuGetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L9
.L8:
	movl	$2, -4(%rbp)
.L9:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	DIO_enuSetPinDirection;	.scl	2;	.type	32;	.endef
	.def	DIO_enuSetPinValue;	.scl	2;	.type	32;	.endef
	.def	DIO_enuGetPinValue;	.scl	2;	.type	32;	.endef
