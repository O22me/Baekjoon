#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
	int count = 0;
	int n;
	cin >> n;
	//100이하인 수는 모두 수열이다. 따라서 그대로 출력하면 맞다!
	if (n < 100) cout << n << '\n';
	else
	{
		count = 99;
		for (int i = 100; i <= n; i++)
		{
			int one = i % 10;
			int ten = (i / 10) % 10;
			int hundred = i / 100;		//1000이 입력되는 예외사항을 고려할 수 있는데 잘 생각해보면 안 그래도 된다.

			if ((hundred - ten) == (ten - one))
			{
				count++;
			}
		}
		cout << count << '\n';
	}

	return 0;
}