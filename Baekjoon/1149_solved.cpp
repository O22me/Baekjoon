#define _CRT_SECURE_NO_WARNINGS
#define FIND_MIN(x, y) ((x) > (y) ? (y) : (x))

#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	int dp[1000][3]; //[i번째 집][색]

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
	}
	for (int i = 1; i < T; i++)
	{
		dp[i][0] += FIND_MIN(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += FIND_MIN(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += FIND_MIN(dp[i - 1][0], dp[i - 1][1]);
	}

	printf("%d\n", FIND_MIN(FIND_MIN(dp[T - 1][0], dp[T - 1][1]), dp[T - 1][2]));

	return 0;
}