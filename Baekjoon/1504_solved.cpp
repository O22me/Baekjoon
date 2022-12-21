#define _CRT_SECURE_NO_WARNINGS
#define INF 2147483647
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1->V1->V2->N �̰ų� 1->V2->V1->N�� �Ǿ����.
���⼺�� ���� �׷����̹Ƿ�, (1-V1�Ÿ�)+(V1-V2�Ÿ�)+(V2-N�Ÿ�)�� (1-V2�Ÿ�)+(V1-V2�Ÿ�)+(V1-N�Ÿ�)�� ª�� ���� ���� ��.
*/
//�ε��� ��ȣ : ������ȣ, pair(����� ����, ����ġ)�Է�
vector<pair<int, int> > node_info[801];

//start���� end������ �ִܰŸ��� ��ȯ
int dijkstra(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

	int distance[801];
	for (int i = 1; i <= 800; i++) distance[i] = INF;
	distance[start] = 0;

	PQ.push(make_pair(0, start));

	while (!PQ.empty())
	{
		//���� ����� ����ġ�� ��ȣ
		int weight = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < node_info[node].size(); i++)
		{
			//����� ���� �� ����ġ
			int related_node = node_info[node][i].first;
			int related_node_weight = node_info[node][i].second;

			//dijkstra �ٽ� : ����ġ �� �� ���� 
			if (related_node_weight + weight < distance[related_node])
			{
				distance[related_node] = related_node_weight + weight;
				PQ.push(make_pair(related_node_weight + weight, related_node));
			}
		}
	}

	//���� : ���ؿ� ������ �� exit()�� ����ϸ� 0�� ��ȯ����.
	if (distance[end] == INF)
	{
		cout << -1 << '\n';
		exit(0);	//����Ǿ� ���� �ʴٸ� ��� �� ���α׷� ����
	}
	return distance[end];
}
int main(int argc, char* argv[])
{
	int N, E;
	int v1, v2;

	cin >> N >> E;

	//�׷��� �Է� : vector�� pair�����Ͽ� �Է�
	while (E--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node_info[a].push_back(make_pair(b, c));
		node_info[b].push_back(make_pair(a, c));
	}

	cin >> v1 >> v2;

	int result = min((dijkstra(1, v1) + dijkstra(v2, N)), (dijkstra(1, v2) + dijkstra(v1, N))) + dijkstra(v1, v2);
	
	cout << result << '\n';

	return 0;
}