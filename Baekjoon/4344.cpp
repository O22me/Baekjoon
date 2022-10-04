#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int C, T;
	scanf("%d", &C);

	for (int i = 0; i < C; i++)
	{
		scanf("%d", &T);
		int score_sum = 0;
		for (int j = 0; j < T; j++)
		{
			int score;
			scanf("%d", &score);
			score_sum += score;
		}
	}

	return 0;
}