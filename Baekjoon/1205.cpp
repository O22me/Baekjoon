#include <iostream>

using namespace std;

int ranking[51] = { 0, };

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, taesu, P;
	int result = 1;

	cin >> N >> taesu >> P;

	for (int i = 0; i < N; i++)
	{
		cin >> ranking[i];
	}

	if (taesu <= ranking[P - 1] && N == P) cout << -1 << '\n';
	else if (N == 0) cout << result;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (taesu < ranking[i]) result++;
			else if (taesu >= ranking[i])
			{
				cout << result;
				break;
			}
		}
	}

	return 0;
}