#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100];
bool visited[101] = { false, };

int bfs(int start_v)
{
	int infested = 0;
	queue<int> q;
	q.push(start_v);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (visited[temp]) continue;		//bfs 특성상 같은 정점이 여러개 queue에 입력된다.
		visited[temp] = true;				//첫 방문이라면 true
		infested++;							//감염
		for (int i = 0; i < graph[temp].size(); i++)	//temp에 연결된 정점만큼 반복
		{
			if (!visited[graph[temp][i]])	//방문한적 없는 정점이라면
			{
				q.push(graph[temp][i]);	//queue에 입력
			}
		}
	}
	return infested;
}

int main(int argc, char* argv[])
{
	int N_com, N_edge;

	cin >> N_com;
	cin >> N_edge;

	while (N_edge--)
	{
		int start_v, end_v;
		cin >> start_v >> end_v;
		
		graph[start_v].push_back(end_v);
		graph[end_v].push_back(start_v);
	}

	cout << bfs(1) - 1;			//첫번째 컴퓨터는 제외한다.

	return 0;
}