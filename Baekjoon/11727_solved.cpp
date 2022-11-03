#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int dp[1001];
	cin >> n;		//n �Է�

	//��ȭ���� ���� �ʱⰪ
	dp[0] = 1;
	dp[1] = 3;

	//��ȭ���� ���� �� ����
	for (int i = 2; i < 1001; i++)
	{
		dp[i] = ((dp[i - 2] * 2) % 10007 + dp[i - 1] % 10007) % 10007;
	}

	cout << dp[n - 1];

	return 0;
}