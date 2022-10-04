#define _CRT_SECURE_NO_WARNINGS
#define FIND_MAX(x, y) ((x) > (y) ? (x) : (y))

#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);	//포도주 개수

	int wine[10001] = { 0, };	//포도주의 양

	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &wine[i]);
	}

	int dp[10001];
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];

	for (int i = 3; i <= T; i++)
	{
		dp[i] = FIND_MAX(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
		dp[i] = FIND_MAX(dp[i], dp[i - 1]);
	}

	printf("%d\n", dp[T]);

	return 0;
}