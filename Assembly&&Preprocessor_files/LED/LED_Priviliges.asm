	.file	"LED_Priviliges.c"
	.text
	.globl	LED_enuInit
	.def	LED_enuInit;	.scl	2;	.type	32;	.endef
	.seh_proc	LED_enuInit
LED_enuInit:
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
.L13:
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinDirection
	movl	%eax, -4(%rbp)
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	testb	%al, %al
	jne	.L4
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	3(%rax), %eax
	cmpb	$1, %al
	jne	.L5
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$0, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L8
.L5:
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	3(%rax), %eax
	testb	%al, %al
	jne	.L7
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L8
.L7:
	movl	$3, -4(%rbp)
	jmp	.L8
.L4:
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	cmpb	$1, %al
	jne	.L9
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	3(%rax), %eax
	cmpb	$1, %al
	jne	.L10
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L8
.L10:
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	3(%rax), %eax
	testb	%al, %al
	jne	.L12
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	-5(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$0, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L8
.L12:
	movl	$3, -4(%rbp)
	jmp	.L8
.L9:
	movl	$3, -4(%rbp)
.L8:
	movzbl	-5(%rbp), %eax
	addl	$1, %eax
	movb	%al, -5(%rbp)
.L3:
	cmpb	$2, -5(%rbp)
	jbe	.L13
	jmp	.L14
.L2:
	movl	$2, -4(%rbp)
.L14:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	LED_enuTurnOn
	.def	LED_enuTurnOn;	.scl	2;	.type	32;	.endef
	.seh_proc	LED_enuTurnOn
LED_enuTurnOn:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L17
	cmpb	$2, 24(%rbp)
	ja	.L18
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	testb	%al, %al
	jne	.L19
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$0, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L23
.L19:
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	cmpb	$1, %al
	jne	.L21
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L23
.L21:
	movl	$3, -4(%rbp)
	jmp	.L23
.L18:
	movl	$3, -4(%rbp)
	jmp	.L23
.L17:
	movl	$2, -4(%rbp)
.L23:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	LED_enuTurnOff
	.def	LED_enuTurnOff;	.scl	2;	.type	32;	.endef
	.seh_proc	LED_enuTurnOff
LED_enuTurnOff:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L26
	cmpb	$2, 24(%rbp)
	ja	.L27
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	testb	%al, %al
	jne	.L28
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L32
.L28:
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	2(%rax), %eax
	cmpb	$1, %al
	jne	.L30
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	$0, %r8d
	movl	%eax, %ecx
	call	DIO_enuSetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L32
.L30:
	movl	$3, -4(%rbp)
	jmp	.L32
.L27:
	movl	$3, -4(%rbp)
	jmp	.L32
.L26:
	movl	$2, -4(%rbp)
.L32:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	LED_enuGetState
	.def	LED_enuGetState;	.scl	2;	.type	32;	.endef
	.seh_proc	LED_enuGetState
LED_enuGetState:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movq	%r8, 32(%rbp)
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L35
	cmpq	$0, 32(%rbp)
	je	.L35
	cmpb	$2, 24(%rbp)
	ja	.L36
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	1(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movq	32(%rbp), %rcx
	movq	%rcx, %r8
	movl	%eax, %ecx
	call	DIO_enuGetPinValue
	movl	%eax, -4(%rbp)
	jmp	.L38
.L36:
	movl	$3, -4(%rbp)
	jmp	.L38
.L35:
	movl	$2, -4(%rbp)
.L38:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	DIO_enuSetPinDirection;	.scl	2;	.type	32;	.endef
	.def	DIO_enuSetPinValue;	.scl	2;	.type	32;	.endef
	.def	DIO_enuGetPinValue;	.scl	2;	.type	32;	.endef
