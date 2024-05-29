#include <iostream>
#include <algorithm>

using namespace std;

int height[20];

int main(int argc, char* argv[])
{
	int P, T, result;

	cin >> P;

	while (P--)
	{
		cin >> T;
		result = 0;

		for (int i = 0; i < 20; i++) cin >> height[i];
		for (int i = 0; i < 20; i++)
		{
			for (int j = i; j < 20; j++)
			{
				if (height[i] > height[j]) result += 1;
			}
		}
		cout << T << " " << result << '\n';
	}

	return 0;
}