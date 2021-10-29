#include <stdio.h>

#define N 4

typedef long array_t[N][N];

void transpose(array_t a){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++i)
		{
			long t1 = a[i][j];
			long t2 = a[j][i];
			a[i][j] = t2;
			a[j][i] = t1;
		}
	}
}