#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000];

int main(int argc, char* argv[])
{
	int n;

	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < 1000; i++)
	{
		dp[i] = min(dp[i - 3] + 1, dp[i - 1] + 1);
	}

	if (dp[n] % 2 == 1) cout << "SK" << endl;
	else cout << "CY" << endl;

	return 0;
}