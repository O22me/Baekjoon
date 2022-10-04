#define _CRT_SECURE_NO_WARNINGS
#define PEEK_MAX(x, y) ((x) > (y) ? (x) : (y))

#include <stdio.h>

int main(void)
{
	int stair;
	scanf("%d", &stair);
	int score[300], dp[300];
	for (int i = 0; i < stair; i++)
	{
		scanf("%d", &score[i]);
	}
	dp[0] = score[0];
	dp[1] = PEEK_MAX(score[0], score[0] + score[1]);
	dp[2] = PEEK_MAX(score[0] + score[2], score[1] + score[2]);
	for (int i = 3; i < stair; i++)
	{
		dp[i] = PEEK_MAX(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
	}
	printf("%d", dp[stair - 1]);

	return 0;
}