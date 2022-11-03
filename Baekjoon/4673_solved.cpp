#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	bool isSelf[10001] = { false };		//출력할 인덱스 저장

	for (int i = 1; i < 10001; i++)		//백준 조건 : 10000
	{
		int number = i;
		int sum = number;
		while (number != 0)
		{
			sum += number % 10;
			number = number / 10;
		}
		if (sum < 10001) isSelf[sum] = true;
	}
	for (int i = 1; i < 10001; i++)
	{
		if (!isSelf[i]) cout << i << endl;
	}

	return 0;
}