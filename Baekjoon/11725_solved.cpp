#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

vector<int> graph[MAX];
int answer[MAX];
bool visited[MAX];

void dfs(int start_v)
{
	visited[start_v] = true;
	for (int i = 0; i < graph[start_v].size(); i++)
	{
		int temp = graph[start_v][i];
		if (!visited[temp])
		{
			answer[temp] = start_v;
			dfs(temp);
		}
	}
}

int main(int argc, char* argv[])
{
	int N;	//노드의 개수
	cin >> N;

	for (int i = 0; i < N - 1; i++)		//N - 1번 반복
	{
		int u, v;	//연결된 두 노드
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);

	for (int i = 2; i <=N; i++) cout << answer[i] << '\n';
	//이제 알게 되어서 남기자면, cout의 endl은 버퍼를 비우는 과정이 포함되어 성능이 떨어진다.
	//출력이 많은 문제의 경우, '\n'을 사용하도록 하자.

	return 0;
}