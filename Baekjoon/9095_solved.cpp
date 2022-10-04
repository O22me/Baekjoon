#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main(void)
{
	int test_case, input;
	scanf("%d", &test_case);

	int dp[11];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	for (int i = 3; i < 11; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	for (int i = 0; i < test_case; i++)
	{
		scanf("%d", &input);
		printf("%d\n", dp[input - 1]);
	}

	return 0;
}