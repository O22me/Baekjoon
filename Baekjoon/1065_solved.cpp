#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
	int count = 0;
	int n;
	cin >> n;
	//100������ ���� ��� �����̴�. ���� �״�� ����ϸ� �´�!
	if (n < 100) cout << n << '\n';
	else
	{
		count = 99;
		for (int i = 100; i <= n; i++)
		{
			int one = i % 10;
			int ten = (i / 10) % 10;
			int hundred = i / 100;		//1000�� �ԷµǴ� ���ܻ����� ����� �� �ִµ� �� �����غ��� �� �׷��� �ȴ�.

			if ((hundred - ten) == (ten - one))
			{
				count++;
			}
		}
		cout << count << '\n';
	}

	return 0;
}