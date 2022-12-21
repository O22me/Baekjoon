#define _CRT_SECURE_NO_WARNINGS
#define INF 1000000			//진짜 나처럼 멍청하게 INF를 11로 잡지말자. 최악의 경우 최대 20,000 * 10 = 200,000이다.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[20010];

void dijkstra(int V, int start)
{
	//오름차순 우선순위 큐 : pair(가중치, 현재 노드)
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ; 

	//start로 부터 거리 저장 배열 선언 및 초기화
	int distance[20001];
	for (int i = 1; i <= V; i++) distance[i] = INF;
	
	distance[start] = 0;

	//시작노드 Priority Queue에 삽입
	PQ.push(make_pair(0, start));

	while (!PQ.empty())
	{
		//가장 작은 가중치를 가진 노드
		int weight = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		//가장 작은 가중치를 가진 노드가 연결된 다른 노드 다음 연산.
		for (int i = 0; i < node_info[node].size(); i++)
		{
			//연결된 노드의 번호와 가중치
			int v = node_info[node][i].first;
			int w = node_info[node][i].second;

			//(현재노드의 가중치와 연결된 노드이 가중치의 합)이 해당 노드의 계산된 가중치보다 작다면 갱신.
			if (weight + w < distance[v])
			{
				distance[v] = weight + w;
				PQ.push(make_pair(weight + w, v));	//갱신했다면 연결된 노드 PQ에 추가
			}
		}
	}

	//출력하기(백준)
	for (int i = 1; i <= V; i++)
	{
		if (distance[i] == INF) printf("INF\n");
		else printf("%d\n", distance[i]);
	}
}

int main(int argc, char* argv[])
{
	int V, E, K;			//정점의 개수(V), 간선의 개수(E), 시작 정점(K)
	cin >> V >> E;
	cin >> K;

	while (E--)
	{
		int u, v, w;
		cin >> u >> v >> w;	//시작정점(u), 도착정점(v), 가중치(w)
		node_info[u].push_back(make_pair(v, w));
	}

	dijkstra(V, K);

	return 0;
}