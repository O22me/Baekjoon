/*
bfs, dfs �� ��� ��� ��밡���ϴ�. �׷��� �ִܰŸ��� ���ϴ� ���������� bfs�� �������.
dfs �� ���� Ž���� �ϱ� ������ ��ΰ� ���� ���� �ð� ���⵵�� Ŀ����.
*/

#include <iostream>
#include <queue>		//bfs�� ���� queue ��� �߰�
#include <algorithm>

using namespace std;

int n, m;
char maze[101][101];					//�̷θ� ������ �迭
int distance_[101][101];				//�� �迭���� �ִܰŸ�
bool visited[101][101] = { false, };	//�湮���� ���� ���� false�� ǥ��

void bfs(int x, int y)	//���α���, ���α���
{
	int max = 10001;		//�ִ�Ÿ� 10000
	int dx[4] = { 0, 0, -1, 1 };	//2���� �迭������ ��ǥ�̵��� ���� �迭 ���� �� �ʱ�ȭ
	int dy[4] = { -1, 1, 0, 0 };

	queue<pair<int, int> > q;	//��ǥ�� �����ϴ� queue
	q.push(make_pair(x, y));		//ù ��ǥ(0, 0) �Է�
	visited[x][y] = true;			//�湮ǥ��
	distance_[x][y] = 1;
	while (!q.empty())				//queue�� �� ������
	{
		pair<int, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = curr.first + dx[i];
			int next_y = curr.second + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)	//ť�� ���� ���� dx, dy�� n*m ���̿� ���Եǰ� 0�̻�����
			{
				if (maze[next_x][next_y] == '1' && !visited[next_x][next_y])		//�����ְ� �湮���� ���� ���(bfs�� ����Ǵ� ���)
				{
					distance_[next_x][next_y] = distance_[curr.first][curr.second] + 1;	//�ش� �迭 �Ÿ���� 
					visited[next_x][next_y] = true;												//�湮ǥ��
					q.push(make_pair(next_x, next_y));											//bfs�� ���� queueǪ��
				}
			}
		}
	}
}

int main(int argc, char* argv[])
{
	cin >> n >> m;	//���α���, ���α���, n���� �ٿ� m���� ���ԵǾ� ����.
	//�̷� �Է�
	for (int i = 0; i < n; i++) cin >> maze[i];

	bfs(0, 0);
	
	cout << distance_[n - 1][m - 1] << endl;	//-1�� ����������.

	return 0;
}