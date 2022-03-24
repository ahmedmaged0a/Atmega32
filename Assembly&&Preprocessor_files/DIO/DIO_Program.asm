	.file	"DIO_Program.c"
	.text
	.globl	DIO_enuInit
	.def	DIO_enuInit;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuInit
DIO_enuInit:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	$58, %eax
	movb	$-1, (%rax)
	movl	$55, %eax
	movb	$-1, (%rax)
	movl	$52, %eax
	movb	$-1, (%rax)
	movl	$49, %eax
	movb	$-1, (%rax)
	movl	$59, %eax
	movb	$0, (%rax)
	movl	$56, %eax
	movb	$0, (%rax)
	movl	$53, %eax
	movb	$0, (%rax)
	movl	$50, %eax
	movb	$0, (%rax)
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuSetPortDirection
	.def	DIO_enuSetPortDirection;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuSetPortDirection
DIO_enuSetPortDirection:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$3, 16(%rbp)
	ja	.L4
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L5
	cmpl	$1, %eax
	jg	.L6
	testl	%eax, %eax
	je	.L7
	jmp	.L8
.L6:
	cmpl	$2, %eax
	je	.L9
	cmpl	$3, %eax
	je	.L10
	jmp	.L8
.L7:
	movl	$58, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L8
.L5:
	movl	$55, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L8
.L9:
	movl	$52, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L8
.L10:
	movl	$49, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	nop
.L8:
	movl	$1, -4(%rbp)
	jmp	.L11
.L4:
	movl	$3, -4(%rbp)
.L11:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuSetPortValue
	.def	DIO_enuSetPortValue;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuSetPortValue
DIO_enuSetPortValue:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$3, 16(%rbp)
	ja	.L14
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L15
	cmpl	$1, %eax
	jg	.L16
	testl	%eax, %eax
	je	.L17
	jmp	.L18
.L16:
	cmpl	$2, %eax
	je	.L19
	cmpl	$3, %eax
	je	.L20
	jmp	.L18
.L17:
	movl	$59, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L18
.L15:
	movl	$56, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L18
.L19:
	movl	$53, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	jmp	.L18
.L20:
	movl	$50, %edx
	movzbl	24(%rbp), %eax
	movb	%al, (%rdx)
	nop
.L18:
	movl	$1, -4(%rbp)
	jmp	.L21
.L14:
	movl	$3, -4(%rbp)
.L21:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuTogglePortValue
	.def	DIO_enuTogglePortValue;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuTogglePortValue
DIO_enuTogglePortValue:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$3, 16(%rbp)
	ja	.L24
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L25
	cmpl	$1, %eax
	jg	.L26
	testl	%eax, %eax
	je	.L27
	jmp	.L28
.L26:
	cmpl	$2, %eax
	je	.L29
	cmpl	$3, %eax
	je	.L30
	jmp	.L28
.L27:
	movl	$59, %eax
	movzbl	(%rax), %eax
	movl	$59, %edx
	notl	%eax
	movb	%al, (%rdx)
	jmp	.L28
.L25:
	movl	$56, %eax
	movzbl	(%rax), %eax
	movl	$56, %edx
	notl	%eax
	movb	%al, (%rdx)
	jmp	.L28
.L29:
	movl	$53, %eax
	movzbl	(%rax), %eax
	movl	$53, %edx
	notl	%eax
	movb	%al, (%rdx)
	jmp	.L28
.L30:
	movl	$50, %eax
	movzbl	(%rax), %eax
	movl	$50, %edx
	notl	%eax
	movb	%al, (%rdx)
	nop
.L28:
	movl	$1, -4(%rbp)
	jmp	.L31
.L24:
	movl	$3, -4(%rbp)
.L31:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuGetPortValue
	.def	DIO_enuGetPortValue;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuGetPortValue
DIO_enuGetPortValue:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movq	%rdx, 24(%rbp)
	movb	%al, 16(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 24(%rbp)
	je	.L34
	cmpb	$3, 16(%rbp)
	ja	.L35
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L36
	cmpl	$1, %eax
	jg	.L37
	testl	%eax, %eax
	je	.L38
	jmp	.L39
.L37:
	cmpl	$2, %eax
	je	.L40
	cmpl	$3, %eax
	je	.L41
	jmp	.L39
.L38:
	movl	$57, %eax
	movzbl	(%rax), %eax
	movq	24(%rbp), %rdx
	movb	%al, (%rdx)
	jmp	.L39
.L36:
	movl	$54, %eax
	movzbl	(%rax), %eax
	movq	24(%rbp), %rdx
	movb	%al, (%rdx)
	jmp	.L39
.L40:
	movl	$51, %eax
	movzbl	(%rax), %eax
	movq	24(%rbp), %rdx
	movb	%al, (%rdx)
	jmp	.L39
.L41:
	movl	$48, %eax
	movzbl	(%rax), %eax
	movq	24(%rbp), %rdx
	movb	%al, (%rdx)
	nop
.L39:
	movl	$1, -4(%rbp)
	jmp	.L43
.L35:
	movl	$3, -4(%rbp)
	jmp	.L43
.L34:
	movl	$2, -4(%rbp)
.L43:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuSetPinDirection
	.def	DIO_enuSetPinDirection;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuSetPinDirection
DIO_enuSetPinDirection:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movl	%r8d, %ecx
	movb	%al, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	%ecx, %eax
	movb	%al, 32(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$3, 16(%rbp)
	ja	.L46
	cmpb	$7, 24(%rbp)
	ja	.L46
	cmpb	$1, 32(%rbp)
	ja	.L46
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L47
	cmpl	$1, %eax
	jg	.L48
	testl	%eax, %eax
	je	.L49
	jmp	.L50
.L48:
	cmpl	$2, %eax
	je	.L51
	cmpl	$3, %eax
	je	.L52
	jmp	.L50
.L49:
	movl	$58, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$58, %edx
	movb	%al, (%rdx)
	movl	$58, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$58, %edx
	movb	%al, (%rdx)
	jmp	.L50
.L47:
	movl	$55, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$55, %edx
	movb	%al, (%rdx)
	movl	$55, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$55, %edx
	movb	%al, (%rdx)
	jmp	.L50
.L51:
	movl	$52, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$52, %edx
	movb	%al, (%rdx)
	movl	$52, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$52, %edx
	movb	%al, (%rdx)
	jmp	.L50
.L52:
	movl	$49, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$49, %edx
	movb	%al, (%rdx)
	movl	$49, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$49, %edx
	movb	%al, (%rdx)
	nop
.L50:
	movl	$1, -4(%rbp)
	jmp	.L53
.L46:
	movl	$3, -4(%rbp)
.L53:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuSetPinValue
	.def	DIO_enuSetPinValue;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuSetPinValue
DIO_enuSetPinValue:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movl	%r8d, %ecx
	movb	%al, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	%ecx, %eax
	movb	%al, 32(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$3, 16(%rbp)
	ja	.L56
	cmpb	$7, 24(%rbp)
	ja	.L56
	cmpb	$1, 32(%rbp)
	ja	.L56
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L57
	cmpl	$1, %eax
	jg	.L58
	testl	%eax, %eax
	je	.L59
	jmp	.L60
.L58:
	cmpl	$2, %eax
	je	.L61
	cmpl	$3, %eax
	je	.L62
	jmp	.L60
.L59:
	movl	$59, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$59, %edx
	movb	%al, (%rdx)
	movl	$59, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$59, %edx
	movb	%al, (%rdx)
	jmp	.L60
.L57:
	movl	$56, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$56, %edx
	movb	%al, (%rdx)
	movl	$56, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$56, %edx
	movb	%al, (%rdx)
	jmp	.L60
.L61:
	movl	$53, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$53, %edx
	movb	%al, (%rdx)
	movl	$53, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$53, %edx
	movb	%al, (%rdx)
	jmp	.L60
.L62:
	movl	$50, %eax
	movzbl	(%rax), %eax
	movl	%eax, %edx
	movzbl	24(%rbp), %eax
	movl	$1, %r8d
	movl	%eax, %ecx
	sall	%cl, %r8d
	movl	%r8d, %eax
	notl	%eax
	andl	%edx, %eax
	movl	$50, %edx
	movb	%al, (%rdx)
	movl	$50, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	32(%rbp), %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	orl	%r8d, %eax
	movl	$50, %edx
	movb	%al, (%rdx)
	nop
.L60:
	movl	$1, -4(%rbp)
	jmp	.L63
.L56:
	movl	$3, -4(%rbp)
.L63:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuToggelPinValue
	.def	DIO_enuToggelPinValue;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuToggelPinValue
DIO_enuToggelPinValue:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$3, 16(%rbp)
	ja	.L66
	cmpb	$7, 24(%rbp)
	ja	.L66
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L67
	cmpl	$1, %eax
	jg	.L68
	testl	%eax, %eax
	je	.L69
	jmp	.L70
.L68:
	cmpl	$2, %eax
	je	.L71
	cmpl	$3, %eax
	je	.L72
	jmp	.L70
.L69:
	movl	$59, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	24(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	xorl	%r8d, %eax
	movl	$59, %edx
	movb	%al, (%rdx)
	jmp	.L70
.L67:
	movl	$56, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	24(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	xorl	%r8d, %eax
	movl	$56, %edx
	movb	%al, (%rdx)
	jmp	.L70
.L71:
	movl	$53, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	24(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	xorl	%r8d, %eax
	movl	$53, %edx
	movb	%al, (%rdx)
	jmp	.L70
.L72:
	movl	$50, %eax
	movzbl	(%rax), %eax
	movl	%eax, %r8d
	movzbl	24(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	xorl	%r8d, %eax
	movl	$50, %edx
	movb	%al, (%rdx)
	nop
.L70:
	movl	$1, -4(%rbp)
	jmp	.L73
.L66:
	movl	$3, -4(%rbp)
.L73:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	DIO_enuGetPinValue
	.def	DIO_enuGetPinValue;	.scl	2;	.type	32;	.endef
	.seh_proc	DIO_enuGetPinValue
DIO_enuGetPinValue:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movq	%r8, 32(%rbp)
	movb	%al, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, 32(%rbp)
	je	.L76
	cmpb	$3, 16(%rbp)
	ja	.L77
	cmpb	$7, 24(%rbp)
	ja	.L77
	movzbl	16(%rbp), %eax
	cmpl	$1, %eax
	je	.L78
	cmpl	$1, %eax
	jg	.L79
	testl	%eax, %eax
	je	.L80
	jmp	.L81
.L79:
	cmpl	$2, %eax
	je	.L82
	cmpl	$3, %eax
	je	.L83
	jmp	.L81
.L80:
	movl	$57, %eax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movq	32(%rbp), %rdx
	movb	%al, (%rdx)
	jmp	.L81
.L78:
	movl	$54, %eax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movq	32(%rbp), %rdx
	movb	%al, (%rdx)
	jmp	.L81
.L82:
	movl	$51, %eax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movq	32(%rbp), %rdx
	movb	%al, (%rdx)
	jmp	.L81
.L83:
	movl	$48, %eax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movzbl	24(%rbp), %eax
	movl	%eax, %ecx
	sarl	%cl, %edx
	movl	%edx, %eax
	andl	$1, %eax
	movq	32(%rbp), %rdx
	movb	%al, (%rdx)
	nop
.L81:
	movl	$1, -4(%rbp)
	jmp	.L85
.L77:
	movl	$3, -4(%rbp)
	jmp	.L85
.L76:
	movl	$2, -4(%rbp)
.L85:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
