#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int P;			//�׽�Ʈ ���̽� ����

	cin >> P;

	for (int i = 0; i < P; i++)	//for���� �̿��ؼ� �ε��� Ȱ��
	{
		int N, M;		//N : �׽�Ʈ ���̽� ��ȣ	, M : ������ �ǿ�����
		int temp, m1 = 0, m2 = 1;
		int count = 0;
		cin >> N >> M;

		while (true)
		{
			if (m1 == 0 && m2 == 1 && count != 0) break;
			//�Ǻ���ġ �� ���ϴ� ���� : ������ ������ �ϴ��� n = (n - 2) + (n - 1)�� ����ȴ�.
			temp = m1;
			m1 = m2;
			m2 = (m1 + temp) % M;
			count++;
		}
		cout << N << ' ' << count << '\n';
	}

	return 0;
}