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
		if (visited[temp]) continue;		//bfs Ư���� ���� ������ ������ queue�� �Էµȴ�.
		visited[temp] = true;				//ù �湮�̶�� true
		infested++;							//����
		for (int i = 0; i < graph[temp].size(); i++)	//temp�� ����� ������ŭ �ݺ�
		{
			if (!visited[graph[temp][i]])	//�湮���� ���� �����̶��
			{
				q.push(graph[temp][i]);	//queue�� �Է�
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

	cout << bfs(1) - 1;			//ù��° ��ǻ�ʹ� �����Ѵ�.

	return 0;
}