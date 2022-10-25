#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];	//vector 배열을 이용한 래프 선언
vector<int> printbfs;				//bfs출력물
vector<int> printdfs;				//dfs 출력물
bool visited[1001] = { false, };	//방문한 정점 표시

void bfs(int start_v)	//bfs는 queue를 이용
{
	queue<int> q;
	q.push(start_v);					//시작정점 queue에 푸시
	visited[start_v] = true;		//시작정점 방문
	while (!q.empty())				//queue가 빌 때까지
	{
		int temp = q.front();		//queue 의 제일 앞 정점
		q.pop();						//queue 하나 정리
		printbfs.push_back(temp);	
		for (int i = 0; i < (int)graph[temp].size(); i++)	//정점이 연결된 정점 개수만큼 반복
		{
			if (!visited[graph[temp][i]])	//연결된 정점 중 방문하지 않았다면
			{
				q.push(graph[temp][i]);	//해당 정점 queue에 푸시
				visited[graph[temp][i]] = true;	//queue에 푸시된 정점은 모두 방문예정 노드
			}
		}
	}
}

void dfs(int start_v)	//dfs는 재귀함수 이용
{
	visited[start_v] = true;			//방문완료
	printdfs.push_back(start_v);		//출력vector에 입력

	for (int i = 0; i < (int)graph[start_v].size(); i++)
	{
		if (!visited[graph[start_v][i]])	//시작정점에 연결된 정점들이 방문하지 않은 경우
		{
			dfs(graph[start_v][i]);		//그 정점에서 dfs시작
		}
	}
}

int main(int argc, char* argv[])
{
	int n, m, start_v;

	cin >> n >> m >> start_v;	//정점의 개수 >> 간선의 개수 >> 그래프 탐색 시작 정점번호

	while (m--)	//간선 입력
	{
		int v1, v2;	//이어진 두 정점
		cin >> v1 >> v2;
		graph[v1].push_back(v2);	//vector 배열에서 인덱스 번호를 정점번호로 사용.
		graph[v2].push_back(v1);	//push_back을 이용해서 연결된 정점 추가
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());	//백준 조건 : 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
	}
	bfs(start_v);
	memset(visited, false, sizeof(visited));
	dfs(start_v);
	for (int i = 0; i < (int)printdfs.size(); i++)		//dfs 출력
	{
		cout << printdfs[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < (int)printbfs.size(); i++)		//bfs 출력
	{
		cout << printbfs[i] << " ";
	}

	return 0;
}