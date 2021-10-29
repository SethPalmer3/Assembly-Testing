#include <stdio.h>

#define N 4

typedef long array_t[N][N];

void transpose(array_t a){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			long t1 = a[i][j];
			long t2 = a[j][i];
			a[i][j] = t2;
			a[j][i] = t1;
		}
	}
}

// access 2D arrays = (*(a + r) + c)
// r = row
// c = col

void opt_transpose(array_t a){
	long temp = 0;
	for (int i = 0; i < N; ++i)
	{
		long *rp = &a[i][0];
		long *rx = &a[0][i];
		for (int j = 0; j < i; ++j)
		{
			temp = *(rp);
			*rp = *rx;
			*rx = temp;
			rp += 1;
			rx += 4;
		}
	}
}

int main(int argc, char const *argv[])
{
	array_t test = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	opt_transpose(test);
	for (int i = 0; i < N; ++i)
	{
		printf("{");
		for (int j = 0; j < N; ++j)
		{
			printf("%ld, ", test[i][j]);
		}
		printf("}, ");
	}
	printf("\n");
	return 0;
}