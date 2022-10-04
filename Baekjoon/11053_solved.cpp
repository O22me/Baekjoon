#define _CRT_SECURE_NO_WARNINGS
#define FIND_MAX(x, y) ((x) > (y) ? (x) : (y))

#include <stdio.h>

int main(void)
{
	int dp[1001], seq[1001];
	int N, result = 1;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &seq[i]);
	}

	dp[0] = 1;
	for (int i = 1; i < N; i++) //i��° ����
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++) //i��° ���� �ݺ���, j�� i��° ���� ����
		{
			if (seq[i] > seq[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
		}
		if (result < dp[i]) result = dp[i];
	}
	printf("%d\n", result);

	return 0;
}