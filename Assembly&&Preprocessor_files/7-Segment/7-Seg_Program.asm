	.file	"7-Seg_Program.c"
	.text
	.globl	SEG_Au8NumDisplay
	.data
	.align 8
SEG_Au8NumDisplay:
	.byte	63
	.byte	6
	.byte	91
	.byte	79
	.byte	102
	.byte	109
	.byte	125
	.byte	7
	.byte	127
	.byte	111
	.text
	.globl	Seven_Segment_enuInit
	.def	Seven_Segment_enuInit;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuInit
Seven_Segment_enuInit:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$1, %r8d
	movl	$0, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	orl	%eax, -8(%rbp)
	movl	$1, %r8d
	movl	$1, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	sall	$2, %eax
	orl	%eax, -8(%rbp)
	movl	$1, %r8d
	movl	$2, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	sall	$4, %eax
	orl	%eax, -8(%rbp)
	movl	$1, %r8d
	movl	$3, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	sall	$6, %eax
	orl	%eax, -8(%rbp)
	movl	$1, %r8d
	movl	$4, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	sall	$8, %eax
	orl	%eax, -8(%rbp)
	movl	$1, %r8d
	movl	$5, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	sall	$10, %eax
	orl	%eax, -8(%rbp)
	movl	$1, %r8d
	movl	$6, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinDirection
	sall	$12, %eax
	orl	%eax, -8(%rbp)
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Seven_Segment_enuDisplayNum
	.def	Seven_Segment_enuDisplayNum;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuDisplayNum
Seven_Segment_enuDisplayNum:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	movl	$0, -4(%rbp)
	cmpb	$9, 16(%rbp)
	ja	.L4
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$0, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	shrb	%al
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$1, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	shrb	$2, %al
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$2, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	shrb	$3, %al
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$3, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$4, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	shrb	$5, %al
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$5, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movzbl	16(%rbp), %eax
	cltq
	leaq	SEG_Au8NumDisplay(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	shrb	$6, %al
	movzbl	%al, %eax
	andl	$1, %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, %r8d
	movl	$6, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, -4(%rbp)
	jmp	.L5
.L4:
	movl	$3, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Seven_Segment_enuEnableCommon
	.def	Seven_Segment_enuEnableCommon;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuEnableCommon
Seven_Segment_enuEnableCommon:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Seven_Segment_enuDisableCommon
	.def	Seven_Segment_enuDisableCommon;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuDisableCommon
Seven_Segment_enuDisableCommon:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Seven_Segment_enuEnableDot
	.def	Seven_Segment_enuEnableDot;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuEnableDot
Seven_Segment_enuEnableDot:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Seven_Segment_enuDisableDot
	.def	Seven_Segment_enuDisableDot;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuDisableDot
Seven_Segment_enuDisableDot:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Seven_Segment_enuClearDisplay
	.def	Seven_Segment_enuClearDisplay;	.scl	2;	.type	32;	.endef
	.seh_proc	Seven_Segment_enuClearDisplay
Seven_Segment_enuClearDisplay:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$0, -4(%rbp)
	movl	$1, %r8d
	movl	$0, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, %r8d
	movl	$1, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, %r8d
	movl	$2, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, %r8d
	movl	$3, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, %r8d
	movl	$4, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, %r8d
	movl	$5, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, %r8d
	movl	$6, %edx
	movl	$0, %ecx
	call	DIO_enuSetPinValue
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	DIO_enuSetPinDirection;	.scl	2;	.type	32;	.endef
	.def	DIO_enuSetPinValue;	.scl	2;	.type	32;	.endef
