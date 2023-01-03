#define _CRT_SECURE_NO_WARNINGS
#define INF 2147483647
#define MAX 100001
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > node_info[MAX];

//start에서 end로 가는 최단 경로를 출력하는 함수(데이크스트라 알고리즘)
int dijkstra(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;	//최소 힙 선언

	//점과의 거리 초기화
	int coor[MAX];		//coor배열 : 인덱스(좌표), 값(좌표까지의 이동시간)
	for (int i = 0; i < MAX; i++) coor[i] = INF;
	coor[start] = 0;

	PQ.push(make_pair(0, start));		//시작 값 : 0, 시작 인덱스 번호 : start

	while (!PQ.empty())
	{
		int time = PQ.top().first;			//현재 노드까지 이동시간
		int current = PQ.top().second;	//현재 노드의 인덱스 번호
		PQ.pop();

		if (current == end) return time;	//가장 작은 값(최소힙)을 가지는 배열 인덱스가 목표라면 그 값을 반환

		if (current * 2 < MAX && time < coor[current * 2])	//범위체크와 그 값 크기 비교
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
	int N, K;				//N : 수빈의 위치, K : 동생의 위치

	cin >> N >> K;

	cout << dijkstra(N, K) << '\n';

	return 0;
}