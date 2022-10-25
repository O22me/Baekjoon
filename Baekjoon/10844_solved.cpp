#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	long long dp[101][10] = { 0, };	//dp[N][마지막 숫자의 추가 계단 가능수] = 1
	long long sum = 0;

	//최초 계단 수 초기화
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i < 101; i++)
	{
		// 점화식 분기
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}

	for (int i = 0; i < 10; i++)
	{
		sum += dp[N][i];
	}

	printf("%lld\n", sum % 1000000000);

	return 0;
}