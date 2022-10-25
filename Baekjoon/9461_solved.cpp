#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);

	long long dp[101];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < 101; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	for (int i = 0; i < T; i++)
	{
		int p;
		scanf("%d", &p);
		printf("%lld\n", dp[p - 1]);
	}

	return 0;
}