#include <stdio.h>

int sum(int from, int to){
	int result = 0;
	loop:
		result += from;
		++from;
	if (from <= to){goto loop;}
	return result;
}
long asm_sum(long from, long to) {
	// Declar and initialize result var – *do not modify*.
	long result = 0;

	// Ensure that argument *from* is in %rdi,
	// argument *to* is in %rsi, *result* is in %rax - *do not
	// modify*.
	__asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
	__asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
	__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));

	// Your x86-64 code goes below - comment each instruction...
	__asm__(
		// TODO - Replace the two lines below with add, compare,
		// jump instructions, labels, etc as necessary to implement
		// the loop.
		".loop:;" // beginning of loop
		"addq %rdi, %rax;" // result += from
		"addq $1, %rdi;" // ++from
		"cmpq %rsi, %rdi;" //from - to
		"jle .loop;" // if (from - to) <= 0
	);
	// Ensure that *result* is in %rax for return - *do not modify*.
	__asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	return result;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", sum((int)5, (int)10));
	printf("%ld\n", asm_sum(5l, 10l));
	return 0;
}