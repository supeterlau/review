	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 11, 1
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	_mark@GOTPCREL(%rip), %rdi
	movl	$0, -4(%rbp)
	callq	_setjmp
	cmpl	$0, %eax
	je	LBB0_2
## %bb.1:
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	callq	_printf
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	callq	_recover
	movl	$1, %edi
	callq	_exit
LBB0_2:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_p
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_recover                ## -- Begin function recover
	.p2align	4, 0x90
_recover:                               ## @recover
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_p                      ## -- Begin function p
	.p2align	4, 0x90
_p:                                     ## @p
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str.4(%rip), %rdi
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	callq	_printf
	movq	_mark@GOTPCREL(%rip), %rdi
	movl	$-1, %esi
	movl	%eax, -4(%rbp)          ## 4-byte Spill
	callq	_longjmp
	.cfi_endproc
                                        ## -- End function
	.comm	_mark,148,4             ## @mark
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"longjmp has been called\n"

L_.str.1:                               ## @.str.1
	.asciz	"setjmp has bee called\n"

L_.str.2:                               ## @.str.2
	.asciz	"Calling function p()\n"

L_.str.3:                               ## @.str.3
	.asciz	"Never reached point ...\n"

L_.str.4:                               ## @.str.4
	.asciz	"Calling longjmp() from function p()\n"

L_.str.5:                               ## @.str.5
	.asciz	"Performing function recover()\n"

.subsections_via_symbols
