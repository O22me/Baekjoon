#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];	//vector �迭�� �̿��� ���� ����
vector<int> printbfs;				//bfs��¹�
vector<int> printdfs;				//dfs ��¹�
bool visited[1001] = { false, };	//�湮�� ���� ǥ��

void bfs(int start_v)	//bfs�� queue�� �̿�
{
	queue<int> q;
	q.push(start_v);					//�������� queue�� Ǫ��
	visited[start_v] = true;		//�������� �湮
	while (!q.empty())				//queue�� �� ������
	{
		int temp = q.front();		//queue �� ���� �� ����
		q.pop();						//queue �ϳ� ����
		printbfs.push_back(temp);	
		for (int i = 0; i < (int)graph[temp].size(); i++)	//������ ����� ���� ������ŭ �ݺ�
		{
			if (!visited[graph[temp][i]])	//����� ���� �� �湮���� �ʾҴٸ�
			{
				q.push(graph[temp][i]);	//�ش� ���� queue�� Ǫ��
				visited[graph[temp][i]] = true;	//queue�� Ǫ�õ� ������ ��� �湮���� ���
			}
		}
	}
}

void dfs(int start_v)	//dfs�� ����Լ� �̿�
{
	visited[start_v] = true;			//�湮�Ϸ�
	printdfs.push_back(start_v);		//���vector�� �Է�

	for (int i = 0; i < (int)graph[start_v].size(); i++)
	{
		if (!visited[graph[start_v][i]])	//���������� ����� �������� �湮���� ���� ���
		{
			dfs(graph[start_v][i]);		//�� �������� dfs����
		}
	}
}

int main(int argc, char* argv[])
{
	int n, m, start_v;

	cin >> n >> m >> start_v;	//������ ���� >> ������ ���� >> �׷��� Ž�� ���� ������ȣ

	while (m--)	//���� �Է�
	{
		int v1, v2;	//�̾��� �� ����
		cin >> v1 >> v2;
		graph[v1].push_back(v2);	//vector �迭���� �ε��� ��ȣ�� ������ȣ�� ���.
		graph[v2].push_back(v1);	//push_back�� �̿��ؼ� ����� ���� �߰�
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());	//���� ���� : �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮
	}
	bfs(start_v);
	memset(visited, false, sizeof(visited));
	dfs(start_v);
	for (int i = 0; i < (int)printdfs.size(); i++)		//dfs ���
	{
		cout << printdfs[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < (int)printbfs.size(); i++)		//bfs ���
	{
		cout << printbfs[i] << " ";
	}

	return 0;
}