#include <iostream>
#include <math.h>
#include <memory.h>		//memset

using namespace std;

bool isprime[1000001];

int main(int argc, char* argv[])
{
	int m, n;				//m�̻� n������ �Ҽ����ϱ�

	cin >> m >> n;

	memset(isprime, true, sizeof(isprime));		//isprime �迭�� true�� ó���Ѵ���, false�� �ɷ����� �۾�

	isprime[0] = false;	//0�� 1�� �Ҽ��� �ƴϴ�.
	isprime[1] = false;
	
	//���� �����ϱ⿡�� 2(¦��)�� 3������ ���� �۾����� ���� �� �ӵ��� ���� ���� ���� ���̴�.
	for (int i = 2; i <= sqrt(n); i++)	//�����佺�׳׽��� ü : ��� ������ ���� ���� ��� ���� ó���� ���� �ʾ� ������..!
	{
		for (int j = i * 2; j <= n; j += i)	//i �� ������� �����ؾ� �Ѵ�. ��, j�� i�� ����� �ۿ��Ѵ�.
		{
			if (j % i == 0) isprime[j] = false;	//������ �������� �Ҽ��� �ƴϴ�.
		}
	}

	for (int i = m; i <= n; i++)	//���
	{
		if (isprime[i]) cout << i << '\n';
	}

	return 0;
}