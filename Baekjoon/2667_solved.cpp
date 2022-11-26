#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool map[25][25];
bool visited[25][25];

int bfs(int x, int y, int map_size)
{
	int count = 0;	//���� �� ���� ����
	queue<pair<int, int> > q;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		count++;
		for (int i = 0; i < 4; i++)
		{
			int next_x = curr.first + dx[i];
			int next_y = curr.second + dy[i];

			if (next_x >= 0 && next_x < map_size && next_y >= 0 && next_y < map_size) //bfs�� ��ǥ�� map�� �϶�
			{
				if (map[next_x][next_y] && !visited[next_x][next_y])
				{
					q.push(make_pair(next_x, next_y));	//�����ְ� �湮���� �ʾҴٸ� q�� �߰�
					visited[next_x][next_y] = true;		//q�� Ǫ�������� �湮�����̹Ƿ�
				}
			}
		}
	}
	return count;
}

int main(int argc, char* argv[])
{
	int N, numberoftown = 0;
	cin >> N;
	vector<int> development;

	//map �Է�
	for (int i = 0; i < N; i++)
	{
		char input[25];
		scanf("%s", input);
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;							//�湮���� ���� ������ falseó��.
			if (input[j] == '0') map[i][j] = false;	//0�̶�� ���� ����
			else map[i][j] = true;						//1�̶�� ���� ����
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] && !visited[i][j])
			{
				development.push_back(bfs(i, j, N));	//���� �ְ� �湮���� �ʾҴٸ�
				numberoftown++;
			}
		}
	}

	sort(development.begin(), development.end());

	printf("%d\n", numberoftown);
	for (int i = 0; i < development.size(); i++)
	{
		printf("%d\n", development[i]);
	}

	return 0;
}