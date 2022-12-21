#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001] = { false, };

void bfs(int start)		//�湮��� trueǥ�ø� ���� bfs
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < graph[temp].size(); i++)	//�� ������ ����� �ٸ� ������ vector�� ����Ǿ� �ִ�.
		{
			if (visited[graph[temp][i]] == false)		//vector��Ұ� �湮���� �ʾҴٸ�(=�湮�� �������� ���ٸ�)
			{
				q.push(graph[temp][i]);					//queue�� �߰�.
				visited[graph[temp][i]] = true;			//�湮������ ���� true�� ǥ��
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
		graph[vertex_1].push_back(vertex_2);		//�ε����� ����, vector���� ����� ���� �߰���.
		graph[vertex_2].push_back(vertex_1);
	}

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == false)		//bfs�� ����� Ƚ����ŭ �������� ������ �þ��.
		{
			bfs(i);
			Connection_Component++;
		}
	}

	cout << Connection_Component << '\n';

	return 0;
}