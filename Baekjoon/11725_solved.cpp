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
	int N;	//����� ����
	cin >> N;

	for (int i = 0; i < N - 1; i++)		//N - 1�� �ݺ�
	{
		int u, v;	//����� �� ���
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);

	for (int i = 2; i <=N; i++) cout << answer[i] << '\n';
	//���� �˰� �Ǿ �����ڸ�, cout�� endl�� ���۸� ���� ������ ���ԵǾ� ������ ��������.
	//����� ���� ������ ���, '\n'�� ����ϵ��� ����.

	return 0;
}