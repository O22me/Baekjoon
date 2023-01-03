#define _CRT_SECURE_NO_WARNINGS
#define INF 2147483647
#define MAX 100001
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[MAX];

//start���� end�� ���� �ִ� ��θ� ����ϴ� �Լ�(����ũ��Ʈ�� �˰���)
int dijkstra(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;	//�ּ� �� ����

	//������ �Ÿ� �ʱ�ȭ
	int coor[MAX];		//coor�迭 : �ε���(��ǥ), ��(��ǥ������ �̵��ð�)
	for (int i = 0; i < MAX; i++) coor[i] = INF;
	coor[start] = 0;

	PQ.push(make_pair(0, start));		//���� �� : 0, ���� �ε��� ��ȣ : start

	while (!PQ.empty())
	{
		int time = PQ.top().first;			//���� ������ �̵��ð�
		int current = PQ.top().second;	//���� ����� �ε��� ��ȣ
		PQ.pop();

		if (current == end) return time;	//���� ���� ��(�ּ���)�� ������ �迭 �ε����� ��ǥ��� �� ���� ��ȯ

		if (current * 2 < MAX && time < coor[current * 2])	//����üũ�� �� �� ũ�� ��
		{
			coor[current * 2] = time;
			PQ.push(make_pair(time, current * 2));
		}
		if (current + 1 < MAX && time + 1 < coor[current + 1])
		{
			coor[current + 1] = time + 1;
			PQ.push(make_pair(time + 1, current + 1));
		}
		if (current - 1 >= 0 && time + 1 < coor[current - 1])
		{
			coor[current - 1] = time + 1;
			PQ.push(make_pair(time + 1, current - 1));
		}
	}
	return coor[end];
}

int main(int argc, char* argv[])
{
	int N, K;				//N : ������ ��ġ, K : ������ ��ġ

	cin >> N >> K;

	cout << dijkstra(N, K) << '\n';

	return 0;
}