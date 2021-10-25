/*
loop:
	movq %rsi, %rcx # save b in reg rcx
	movl $1, %eax # set return value to 1
	movl $0, %edx # result = 0
.L2:
	testq %rax, %rax # test to see if %rax is pos, neg, or 0
	je .L4 # jump to .L4 if rax is 0 or negative
	movq %rax, %r8 # set reg 8 to mask
	andq %rdi, %r8 # %mask &= a
	orq %r8, %rdx # result |= %r8
	salq %cl, %rax # %rax <<= %cl(1 byte of %rcx)
	jmp .L2 # jump back to beginning of for loop
.L4
	movq %rdx, %rax # result = ?
	ret
*/

#include <stdio.h>

long loop(long a, long b){
	long result = 0;
	for(long mask = 0x1; mask != 0; mask <<= b){
		result |= (a & mask);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	printf("%ld\n", loop(1, 5));
	printf("%ld\n", loop(2, 4));
	printf("%ld\n", loop(3, 3));
	printf("%ld\n", loop(4, 2));
	printf("%ld\n", loop(5, 1));
	return 0;
}