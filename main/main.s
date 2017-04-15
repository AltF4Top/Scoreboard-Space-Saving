	.file	"main.cpp"
	.local	_ZL3ssh
	.comm	_ZL3ssh,152,32
	.local	_ZL2ss
	.comm	_ZL2ss,72,32
	.local	_ZL3stk
	.comm	_ZL3stk,56,32
	.local	_ZL3key
	.comm	_ZL3key,50,32
	.local	_ZL6sshAns
	.comm	_ZL6sshAns,408,32
	.local	_ZL5ssAns
	.comm	_ZL5ssAns,408,32
	.local	_ZL6stkAns
	.comm	_ZL6stkAns,408,32
	.local	_ZL8ssh_rate
	.comm	_ZL8ssh_rate,8,8
	.local	_ZL7ss_rate
	.comm	_ZL7ss_rate,8,8
	.section	.rodata
.LC0:
	.string	"rb"
	.align 8
.LC1:
	.string	"/home/lenovo/Documents/laboratery/CBFQueSS/data/u2"
.LC2:
	.string	"t = %d\n"
.LC4:
	.string	"%d\n"
.LC5:
	.string	"%d %d %d\n"
.LC6:
	.string	"%d %d\n"
.LC7:
	.string	"a"
	.align 8
.LC8:
	.string	"/home/lenovo/Documents/laboratery/CBFQueSS/result/pr_freq_real_phi.txt"
.LC9:
	.string	"%.8lf,%.10lf,%.10lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB921:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$0, -56(%rbp)
.L4:
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	movl	$_ZL3key, %edi
	call	fread
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L2
	movl	$_ZL3key, %esi
	movl	$_ZL3ssh, %edi
	call	_ZN7SSH_CBF6insertEPKc
	movl	$_ZL3key, %esi
	movl	$_ZL2ss, %edi
	call	_ZN2SS6insertEPKc
	movl	$_ZL3key, %esi
	movl	$_ZL3stk, %edi
	call	_ZN7StdTopK6insertEPKc
	addl	$1, -56(%rbp)
	movl	-56(%rbp), %ecx
	movl	$1125899907, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$18, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$1000000, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	sete	%al
	testb	%al, %al
	je	.L4
	movl	-56(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L4
.L2:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	pxor	%xmm0, %xmm0
	cvtsi2sd	-56(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %rax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	-20(%rbp), %eax
	movl	$_ZL6sshAns, %edx
	movl	%eax, %esi
	movl	$_ZL3ssh, %edi
	call	_ZN7SSH_CBF7GetFreqEjPPc
	movl	-20(%rbp), %eax
	movl	$_ZL5ssAns, %edx
	movl	%eax, %esi
	movl	$_ZL2ss, %edi
	call	_ZNK2SS7GetFreqEjPPc
	movl	-20(%rbp), %eax
	movl	$_ZL6stkAns, %edx
	movl	%eax, %esi
	movl	$_ZL3stk, %edi
	call	_ZNK7StdTopK7GetFreqEjPPc
	movl	$0, -52(%rbp)
.L6:
	movl	-52(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -52(%rbp)
	movl	%eax, %eax
	movq	_ZL6sshAns(,%rax,8), %rax
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L5
	jmp	.L6
.L5:
	subl	$1, -52(%rbp)
	movl	$0, -48(%rbp)
.L8:
	movl	-48(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -48(%rbp)
	movl	%eax, %eax
	movq	_ZL5ssAns(,%rax,8), %rax
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L7
	jmp	.L8
.L7:
	subl	$1, -48(%rbp)
	movl	$0, -44(%rbp)
.L10:
	movl	-44(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -44(%rbp)
	movl	%eax, %eax
	movq	_ZL6stkAns(,%rax,8), %rax
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L9
	jmp	.L10
.L9:
	subl	$1, -44(%rbp)
	movl	-44(%rbp), %ecx
	movl	-48(%rbp), %edx
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -40(%rbp)
	movl	$0, -36(%rbp)
.L16:
	movl	-36(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jnb	.L11
	movl	-36(%rbp), %eax
	movq	_ZL6sshAns(,%rax,8), %rax
	testq	%rax, %rax
	je	.L12
	movl	$0, -32(%rbp)
.L15:
	movl	-32(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jnb	.L12
	movl	-32(%rbp), %eax
	movq	_ZL6stkAns(,%rax,8), %rax
	testq	%rax, %rax
	je	.L14
	movl	-32(%rbp), %eax
	movq	_ZL6stkAns(,%rax,8), %rdx
	movl	-36(%rbp), %eax
	movq	_ZL6sshAns(,%rax,8), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L14
	addl	$1, -40(%rbp)
	jmp	.L12
.L14:
	addl	$1, -32(%rbp)
	jmp	.L15
.L12:
	addl	$1, -36(%rbp)
	jmp	.L16
.L11:
	movl	-52(%rbp), %edx
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	-40(%rbp), %eax
	testq	%rax, %rax
	js	.L17
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L18
.L17:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L18:
	movl	-52(%rbp), %eax
	testq	%rax, %rax
	js	.L19
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	jmp	.L20
.L19:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rdx, %xmm1
	addsd	%xmm1, %xmm1
.L20:
	divsd	%xmm1, %xmm0
	movsd	%xmm0, _ZL8ssh_rate(%rip)
	movl	$0, -40(%rbp)
	movl	$0, -28(%rbp)
.L26:
	movl	-28(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jnb	.L21
	movl	-28(%rbp), %eax
	movq	_ZL5ssAns(,%rax,8), %rax
	testq	%rax, %rax
	je	.L22
	movl	$0, -24(%rbp)
.L25:
	movl	-24(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jnb	.L22
	movl	-24(%rbp), %eax
	movq	_ZL6stkAns(,%rax,8), %rax
	testq	%rax, %rax
	je	.L24
	movl	-24(%rbp), %eax
	movq	_ZL6stkAns(,%rax,8), %rdx
	movl	-28(%rbp), %eax
	movq	_ZL5ssAns(,%rax,8), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp
	testl	%eax, %eax
	jne	.L24
	addl	$1, -40(%rbp)
	jmp	.L22
.L24:
	addl	$1, -24(%rbp)
	jmp	.L25
.L22:
	addl	$1, -28(%rbp)
	jmp	.L26
.L21:
	movl	-48(%rbp), %edx
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	-40(%rbp), %eax
	testq	%rax, %rax
	js	.L27
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L28
.L27:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L28:
	movl	-48(%rbp), %eax
	testq	%rax, %rax
	js	.L29
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	jmp	.L30
.L29:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rdx, %xmm1
	addsd	%xmm1, %xmm1
.L30:
	divsd	%xmm1, %xmm0
	movsd	%xmm0, _ZL7ss_rate(%rip)
	movl	$.LC7, %esi
	movl	$.LC8, %edi
	call	fopen
	movq	%rax, -8(%rbp)
	movsd	_ZL7ss_rate(%rip), %xmm1
	movsd	_ZL8ssh_rate(%rip), %xmm0
	movabsq	$4551510721646314285, %rdx
	movq	-8(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rdx, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	movl	$.LC9, %esi
	movq	%rax, %rdi
	movl	$3, %eax
	call	fprintf
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fflush
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE921:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB922:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L34
	cmpl	$65535, -8(%rbp)
	jne	.L34
	movabsq	$4551510721646314285, %rax
	pushq	$10
	pushq	$50
	movq	%rax, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	movl	$12, %r9d
	movl	$1500, %r8d
	movl	$3, %ecx
	movl	$50, %edx
	movl	$50, %esi
	movl	$_ZL3ssh, %edi
	call	_ZN7SSH_CBFC1Ejjjjjjjd
	addq	$16, %rsp
	movl	$__dso_handle, %edx
	movl	$_ZL3ssh, %esi
	movl	$_ZN7SSH_CBFD1Ev, %edi
	call	__cxa_atexit
	movl	$50, %edx
	movl	$50, %esi
	movl	$_ZL2ss, %edi
	call	_ZN2SSC1Ejj
	movl	$__dso_handle, %edx
	movl	$_ZL2ss, %esi
	movl	$_ZN2SSD1Ev, %edi
	call	__cxa_atexit
	movl	$50, %esi
	movl	$_ZL3stk, %edi
	call	_ZN7StdTopKC1Ej
	movl	$__dso_handle, %edx
	movl	$_ZL3stk, %esi
	movl	$_ZN7StdTopKD1Ev, %edi
	call	__cxa_atexit
.L34:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE922:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB923:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE923:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
.LC3:
	.long	3944497965
	.long	1059731170
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
