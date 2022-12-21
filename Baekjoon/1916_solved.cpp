#define _CRT_SECURE_NO_WARNINGS
#define INF 2147483647
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[100001];
int N, M;		//N : ������ ����(����), M :  ������ ����(����)

//start���� end�� ���� �ִ� ��θ� ����ϴ� �Լ�(����ũ��Ʈ�� �˰���)
int dijkstra(int start, int end)
{
	if (start == end) return 0;	//ó���ӵ� ����� ���� �ܼ� Ʈ����
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

	int distance[1001];
	for (int i = 1; i <= N; i++) distance[i] = INF;
	distance[start] = 0;

	//�ð��ʰ� : �Ʒ� �κ��� �� �� ȿ�������� ���� �ʿ�
	PQ.push(make_pair(0, start));

	while (!PQ.empty())
	{
		//���� ����� ����ġ�� ��ȣ
		int weight = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		//�ð��ʰ� �ذ�
		if (distance[node] < weight) continue;

		/*
		//���� �������� ���� ����ġ ������ �ְ� �� ���� �۴ٸ� �ٷ� ��ȯ�ص� ����(�ֳĸ� �켱���� ť�� ���ؼ� �ڵ����� ���� ���� ���� �����ϱ�.
		//�ð��ʰ�
		if (node == end && weight < distance[node]) return weight;
		*/

		for (int i = 0; i < node_info[node].size(); i++)
		{
			//����� ���� �� ����ġ
			int related_node = node_info[node][i].first;
			int related_node_weight = node_info[node][i].second + weight;

			//dijkstra �ٽ� : ����ġ �� �� ���� 
			if (related_node_weight < distance[related_node])
			{
				distance[related_node] = related_node_weight;
				PQ.push(make_pair(related_node_weight, related_node));
			}
		}
	}
	return distance[end];
}

int main(int argc, char* argv[])
{
	int start, end;

	cin >> N >> M;	//N : ������ ����, M : ������ ����

	while (M--)
	{
		int A, B, cost;
		cin >> A >> B >> cost;
		node_info[A].push_back(make_pair(B, cost));
	}

	cin >> start >> end;
	cout << dijkstra(start, end) << '\n';

	return 0;
}