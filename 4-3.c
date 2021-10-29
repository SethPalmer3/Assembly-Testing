#include <stdio.h>

long fact(long x){ //pushes original %rdi to the stack to give back control
	if (x <= 1)
	{
		return 1;
	}
	long px = x;
	long fx = fact(x - 1);
	return px * fx; //pops back %rdi to give control back to the call previous
}

int main(int argc, char const *argv[])
{
	printf("%ld\n", fact(2));
	return 0;
}