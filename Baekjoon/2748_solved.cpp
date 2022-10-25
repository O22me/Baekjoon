#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	long long dp[91];
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i < 91; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	printf("%lld", dp[n]);

	return 0;
}