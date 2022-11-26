#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int value)
{
	int root = sqrt(value);
	if (value != 1 && root == 1)	//value�� 1�� �ƴϰ� ������ ���� 1�� ����(�������) : 2, 3
	{
		return true;
	}
	if (value % 2 != 0)								//¦���� �����ϸ� ¦���̹Ƿ� �����Ѵ�. ¦�� != �Ҽ�
	{
		for (int j = 2; j <= root; j++)			//�����佺�׳׽��� ü
		{
			if (value % j == 0) return false;		//������ �������� �Ҽ��� �ƴ�.
			if (j == root) return true;				//�����ٱ��� ���� for�� ���� �� �Ҽ��� ����
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

		for (int i = input / 2; i >= 2; i--)			//�������� ������
		{
			if (isPrime(i) && isPrime(input - i))	//���� ����� �Ҽ����� ã�� ����
			{
				cout << i << ' ' << input - i << endl;
				break;
			}
		}
	}

	return 0;
}