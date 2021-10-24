/*
loop:
	movq %rsi, %rcx
	movl $1, %eax
	movl $0, edx
.L2:
	testq %rax, %rax
	je .L4
	movq %rax, %r8
	andq %rdi, %r8
	orq %r8, %rdx
	salq %cl, %rax
	jmp .L2
.L4
	movq %rdx, %raxs
*/