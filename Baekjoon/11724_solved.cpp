#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001] = { false, };

void bfs(int start)		//방문노드 true표시를 위한 bfs
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < graph[temp].size(); i++)	//각 정점에 연결된 다른 정점은 vector로 저장되어 있다.
		{
			if (visited[graph[temp][i]] == false)		//vector요소가 방문하지 않았다면(=방문할 예정에도 없다면)
			{
				q.push(graph[temp][i]);					//queue에 추가.
				visited[graph[temp][i]] = true;			//방문예정인 노드는 true로 표시
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int N, M;
	int Connection_Component = 0;

	cin >> N >> M;

	while(M--)
	{
		int vertex_1, vertex_2;
		cin >> vertex_1 >> vertex_2;
		graph[vertex_1].push_back(vertex_2);		//인덱스는 정점, vector내에 연결된 정점 추가됨.
		graph[vertex_2].push_back(vertex_1);
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)		//bfs가 실행된 횟수만큼 연결요소의 개수가 늘어난다.
		{
			bfs(i);
			Connection_Component++;
		}
	}

	cout << Connection_Component << '\n';

	return 0;
}