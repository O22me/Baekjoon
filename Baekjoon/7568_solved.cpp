#include <iostream>

using namespace std;

int weight[50];
int height[50];
int ranking[50];
int result;

int main(int argc, char* argv[])
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> weight[i] >> height[i];
	}

	for (int i = 0; i < N; i++)
	{
		result = 1;
		for (int j = 0; j < N; j++)
		{
			if (weight[i] < weight[j] && height[i] < height[j])
			{
				result++;
			}
		}
		ranking[i] = result;
	}

	for (int i = 0; i < N; i++)
	{
		cout << ranking[i] << ' ';
	}

	return 0;
}