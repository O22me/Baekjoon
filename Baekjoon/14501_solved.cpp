#define _CRT_SECURE_NO_WARNINGS
#define FIND_MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX 20
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int N;

	cin >> N;	//�ִ� 15

	int dp[MAX] = { 0, };	//dp[i] : i ~ N������ �ִ� ����
	int Ti[MAX] = { 0, };	//�ҿ�ð�
	int Pi[MAX] = { 0, };	//��㺸��

	for (int i = 1; i <= N; i++) cin >> Ti[i] >> Pi[i];

	//DP������ �ڿ��� �����ϴ� ���� ���� ����� �ȴ�.
	for (int j = N; j > 0; j--)
	{
		if (Ti[j] > N - j + 1) dp[j] = dp[j + 1];							//���� �� �� �� �ִ� ���� ���
		else dp[j] = FIND_MAX(dp[j + Ti[j]] + Pi[j], dp[j + 1]);	//�ٽ� : j�Ͽ� ����� ������ ���ΰ�. FIND_MAX(����, ������)
	}

	cout << dp[1] << '\n';

	return 0;
}