#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int N, total = 0, temp = 0; //���� ���� ����� ��
	vector<int> waiting_time;	//��ٸ��� �ð��� �����ϴ� vector ����

	cin >> N;

	while (N--)	//�������ŭ �Է�
	{
		int time;
		cin >> time;
		waiting_time.push_back(time);
	}

	sort(waiting_time.begin(), waiting_time.end()); //�׸��� �˰����� ���� ����

	for (int i = 0; i < waiting_time.size(); i++)
	{
		temp += waiting_time[i];
		total += temp;
	}

	cout << total;

	return 0;
}