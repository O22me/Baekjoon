#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	long long N;
	cin >> N;

	long long dp[91];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[N] << endl;

	return 0;
}