#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int value)
{
	int root = sqrt(value);
	if (value != 1 && root == 1)	//value가 1이 아니고 제곱근 값이 1이 나옴(버림계산) : 2, 3
	{
		return true;
	}
	if (value % 2 != 0)								//짝수를 제곱하면 짝수이므로 제외한다. 짝수 != 소수
	{
		for (int j = 2; j <= root; j++)			//에라토스테네스의 체
		{
			if (value % j == 0) return false;		//나누어 떨어지면 소수가 아님.
			if (j == root) return true;				//제곱근까지 오면 for문 종료 및 소수라 판정
		}
	}
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	while (T--)
	{
		int input;
		cin >> input;

		for (int i = input / 2; i >= 2; i--)			//절반으로 나눈뒤
		{
			if (isPrime(i) && isPrime(input - i))	//제일 가까운 소수부터 찾는 과정
			{
				cout << i << ' ' << input - i << endl;
				break;
			}
		}
	}

	return 0;
}