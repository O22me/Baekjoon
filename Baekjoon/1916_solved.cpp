#define _CRT_SECURE_NO_WARNINGS
#define INF 2147483647
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[100001];
int N, M;		//N : 도시의 개수(정점), M :  버스의 개수(간선)

//start에서 end로 가는 최단 경로를 출력하는 함수(데이크스트라 알고리즘)
int dijkstra(int start, int end)
{
	if (start == end) return 0;	//처리속도 향상을 위한 단순 트리거
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

	int distance[1001];
	for (int i = 1; i <= N; i++) distance[i] = INF;
	distance[start] = 0;

	//시간초과 : 아래 부분을 좀 더 효율적으로 개선 필요
	PQ.push(make_pair(0, start));

	while (!PQ.empty())
	{
		//현재 노드의 가중치와 번호
		int weight = PQ.top().first;
		int node = PQ.top().second;
		PQ.pop();

		//시간초과 해결
		if (distance[node] < weight) continue;

		/*
		//만약 목적지에 대한 가중치 정보가 있고 그 값이 작다면 바로 반환해도 무방(왜냐면 우선순위 큐에 의해서 자동으로 가장 적은 값이 나오니까.
		//시간초과
		if (node == end && weight < distance[node]) return weight;
		*/

		for (int i = 0; i < node_info[node].size(); i++)
		{
			//연결된 노드와 그 가중치
			int related_node = node_info[node][i].first;
			int related_node_weight = node_info[node][i].second + weight;

			//dijkstra 핵심 : 가중치 비교 후 갱신 
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

	cin >> N >> M;	//N : 도시의 개수, M : 버스의 개수

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