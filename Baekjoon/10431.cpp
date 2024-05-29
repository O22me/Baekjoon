#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int steps(queue<int> height)
{
	int count = 0;
	int max = height.front();
	height.pop();

	for (int i = 0; i < height.size(); i++)
	{
		if (max < height.front())
		{

		}
	}


	return count;
}

int main(int argc, char* argv[])
{
	int P;
	int number, how_tall;
	vector<pair<int, int> > test_case;	// 테스트 케이스 번호, 결과 값.
	queue<int> height;

	cin >> P;

	while (P--)
	{
		cin >> number;							// 테스트 케이스 번호 입력

		for (int i = 0; i < 20; i++)
		{
			cin >> how_tall;
			height.push(how_tall);					// 첫번째 키입력
		}

		test_case.push_back({ number, steps(height) });	// 테스트 케이스 번호 입력, 걸음수 입력.
	}

	for (int i = 0; i < test_case.size(); i++)
	{
		cout << test_case.at(i).first << test_case.at(i).second << endl;
	}

	return 0;
}