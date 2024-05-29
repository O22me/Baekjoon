#include <iostream>

using namespace std;

int result = 0;
int gold[1001];
int silver[1001];
int bronze[1001];

int main(int argc, char* argv[])
{
	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		cin >> gold[number] >> silver[number] >> bronze[number];
	}

	for (int i = 1; i <= N; i++)
	{
		if (gold[i] > gold[K])
		{
			result++;
		}
		else if (gold[i] == gold[K])
		{
			if (silver[i] > silver[K])
			{
				result++;
			}
			else if (silver[i] == silver[K])
			{
				if (bronze[i] > bronze[K])
				{
					result++;
				}
			}
		}
	}	

	cout << result + 1 << '\n';

	return 0;
}