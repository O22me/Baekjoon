#define _CRT_SECURE_NO_WARNINGS
#define INF 2147483647
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1->V1->V2->N 이거나 1->V2->V1->N가 되어야함.
방향성이 없는 그래프이므로, (1-V1거리)+(V1-V2거리)+(V2-N거리)와 (1-V2거리)+(V1-V2거리)+(V1-N거리)중 짧은 것을 택할 것.
*/
//인덱스 번호 : 정점번호, pair(연결된 정점, 가중치)입력
vector<pair<int, int> > node_info[801];

//start부터 end까지의 최단거리를 반환
int dijkstra(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

	int distance[801];
	for (int i = 1; i <= 800; i++) distance[i] = INF;
	distance[start] = 0;

	PQ.push(make_pair(0, start));

	while (!PQ.empty())
	{
		//현재 노드의 가중치와 번호
		int weight = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < node_info[node].size(); i++)
		{
			//연결된 노드와 그 가중치
			int related_node = node_info[node][i].first;
			int related_node_weight = node_info[node][i].second;

			//dijkstra 핵심 : 가중치 비교 후 갱신 
			if (related_node_weight + weight < distance[related_node])
			{
				distance[related_node] = related_node_weight + weight;
				PQ.push(make_pair(related_node_weight + weight, related_node));
			}
		}
	}

	//번외 : 백준에 제출할 때 exit()를 사용하면 0을 반환하자.
	if (distance[end] == INF)
	{
		cout << -1 << '\n';
		exit(0);	//연결되어 있지 않다면 출력 후 프로그램 종료
	}
	return distance[end];
}
int main(int argc, char* argv[])
{
	int N, E;
	int v1, v2;

	cin >> N >> E;

	//그래프 입력 : vector에 pair생성하여 입력
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