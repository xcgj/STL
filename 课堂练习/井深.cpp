#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int j = 10000000;
	for (int a = 1; a < j; a++)
	{
		for (int b = 1; b < j; j++)
		{
			for (int c = 1; c < j; c++)
			{
				for (int d = 1; d < j; d++)
				{
					for (int e = 1; e < j; e++)
					{
						if (a + b == 5 * e&&a * 2 == b * 2 + c&&b * 3 == 3 * c + d && 4 * c == 4 * d + e && 5 * d == 5 * e + a)
							printf("%d,%d,%d,%d,%d\n", a, b, c, d, e);
					}
				}
			}
		}
	}
	printf("Compelete\n");
	return 0;
}
