#define _CRT_SECURE_NO_WARNINGS
#define INF 1000000			//��¥ ��ó�� ��û�ϰ� INF�� 11�� ��������. �־��� ��� �ִ� 20,000 * 10 = 200,000�̴�.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[20010];

void dijkstra(int V, int start)
{
	//�������� �켱���� ť : pair(����ġ, ���� ���)
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; 

	//start�� ���� �Ÿ� ���� �迭 ���� �� �ʱ�ȭ
	int distance[20001];
	for (int i = 1; i <= V; i++) distance[i] = INF;
	
	distance[start] = 0;

	//���۳�� Priority Queue�� ����
	PQ.push(make_pair(0, start));

	while (!PQ.empty())
	{
		//���� ���� ����ġ�� ���� ���
		int weight = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		//���� ���� ����ġ�� ���� ��尡 ����� �ٸ� ��� ���� ����.
		for (int i = 0; i < node_info[node].size(); i++)
		{
			//����� ����� ��ȣ�� ����ġ
			int v = node_info[node][i].first;
			int w = node_info[node][i].second;

			//(�������� ����ġ�� ����� ����� ����ġ�� ��)�� �ش� ����� ���� ����ġ���� �۴ٸ� ����.
			if (weight + w < distance[v])
			{
				distance[v] = weight + w;
				PQ.push(make_pair(weight + w, v));	//�����ߴٸ� ����� ��� PQ�� �߰�
			}
		}
	}

	//����ϱ�(����)
	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == INF) printf("INF\n");
		else printf("%d\n", distance[i]);
	}
}

int main(int argc, char* argv[])
{
	int V, E, K;			//������ ����(V), ������ ����(E), ���� ����(K)
	cin >> V >> E;
	cin >> K;

	while (E--)
	{
		int u, v, w;
		cin >> u >> v >> w;	//��������(u), ��������(v), ����ġ(w)
		node_info[u].push_back(make_pair(v, w));
	}

	dijkstra(V, K);

	return 0;
}