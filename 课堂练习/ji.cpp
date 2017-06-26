#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int a, b, c;
	int i, j, k, count;
	i = j = k = count = 0;
	for (; i <= 20; i++)
		for (j = 0; j <= 33; j++)
			for (k = 0; k <= 100; k+=3)
				if ((5*i+3*j+k/3 == 100) && (i+j+k == 100))
				{
					count++;
				}
	printf("%d\n", count);
	return 0;
}
