#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int distance = 1;
	int dp[2] = { 0, 1 };

	cin >> n;

	while (true)
	{
		if (n > dp[0] && n <= dp[1])
		{
			cout << distance << endl;
			break;
		}
		distance++;
		dp[0] = dp[1];
		dp[1] += (distance - 1) * 6;
	}

	return 0;
}