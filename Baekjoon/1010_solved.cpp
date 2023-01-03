#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int ncr[31][31];

int main(int argc, char* argv[])
{
	int T;

	cin >> T;

	for (int i = 0; i < 31; i++)
	{
		ncr[i][i] = 1;
		ncr[i][1] = i;
	}

	//n = 3, r = 2 부터 시작하는 이중 반복문
	for (int n = 2; n < 31; n++)	
	{
		for (int r = 2; r < 31; r++)
		{
			if (n > r) ncr[n][r] = ncr[n - 1][r] + ncr[n - 1][r - 1];
		}
	}

	while (T--)
	{
		int N, M;

		cin >> N >> M;

		cout << ncr[M][N] << '\n';
	}

	return 0;
}