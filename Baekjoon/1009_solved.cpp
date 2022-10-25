#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		long a, b;
		scanf("%d %d", &a, &b);

		b = b % 4 + 4;

		long result = a;
		for (int j = 2; j <= b; j++)
		{
			result = (result * a) % 10;
		}
		if (result == 0) result = 10;

		printf("%d\n", result);
	}

	return 0;
}