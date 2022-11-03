#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int N, K, count = 0;

	vector<int> type_of_coin(10);

	cin >> N >> K;	//������ ����, ������� ��ġ ��

	for (int i = 0; i < N; i++)
	{
		cin >> type_of_coin[i];
	}

	//�׸��� �˰���
	for (int i = N; i >= 0 && !(K == 0); i--)
	{
		if (K >= type_of_coin[i])
		{
			count += (K / type_of_coin[i]);
			K = K % type_of_coin[i];
		}
	}

	cout << count << endl;

	return 0;
}