#define _CRT_SECURE_NO_WARNINGS
#define INF 100001
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[1001];

int N, M, X;					//N : 학생수(마을수), M : 간선의 수, X :  모이는 마을번호

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

		//만약 목적지에 대한 가중치 정보가 있고 그 값이 작다면 바로 반환해도 무방?(왜냐면 우선순위 큐에 의해서 자동으로 가장 적은 값이 나오니까.
		//추가됨(시간초과 해결)
		if (node == end && weight < distance[node]) return weight;

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
	return distance[end];
}

int main(int argc, char* argv[])
{
	int result = 0;

	cin >> N >> M >> X;

	//간선 가중치 입력
	while (M--)
	{
		int start, end, time;
		cin >> start >> end >> time;
		node_info[start].push_back(make_pair(end, time));	//단방향 그래프이다.
	}

	for (int i = 1; i <= N; i++)
	{
		int distance = dijkstra(i, X) + dijkstra(X, i);	//갔다가 돌아오니까.
		if (distance > result) result = distance;		//최대값 갱신
	}

	cout << result << '\n';

	return 0;
}