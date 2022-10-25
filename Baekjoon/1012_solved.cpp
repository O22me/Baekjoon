#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

bool field[51][51] = { false, };	//bool �迭 false�� �ڵ� �ʱ�ȭ.
bool visited[51][51] = { false, };

void dfs(int x, int y, int n, int m)
{
	visited[x][y] = true;
	//�����¿��� dfs�� �����ؾ���.
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	//4���� ����
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (x >= 0 && x < n && y >= 0 && y < m)	//(x, y)�� ��ǥ�� ���߹�ȿ� ��ġ�ϴ���
		{
			if (field[nx][ny] && !visited[nx][ny]) dfs(nx, ny, n, m);	//��͸� �̿��� dfs
		}
	}
}

int main(int argc, char* argv[])
{
	int T;
	cin >> T;

	while (T--)
	{
		int group = 0;
		int m, n, k;//m�� ���α���, n�� ���α���
		cin >> m >> n >> k;
		//field : ���߰� �ɾ��� ��, visited : �׷��� ��ȯ�� ���� �湮 ��� ǥ��
		while (k--)	//���߰� �ɾ��� �ִ� ��ġ�� �Է�
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = true;	//y�� ���α���, x�� ���α���
		}
		//�� field�� ���鼭 ���� �߽߰� dfs������ ���� visited �迭 ����
		for (int i = 0; i < n; i++)			//i : ����
		{
			for (int j = 0; j < m; j++)	//j : ����
			{
				if (field[i][j] && !visited[i][j])	//���ο� �׷�(����) �߰�
				{
					group++;
					dfs(i, j, n, m);
				}
			}
		}
		cout << group << endl;
		//���� �׽�Ʈ ���̽��� ���� �ʱ�ȭ
		memset(visited, false, sizeof(visited));
		memset(field, false, sizeof(field));
	}

	return 0;
}