#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int wall = 0, virus = 0;
int map[8][8];						//������ ����
vector<pair<int, int> > blank;	//��ĭ ��ǥ

int safe_zone_bfs()
{
	queue<pair<int, int> > q;		//���̷��� ��ǥ(bfs�� Ȱ���� ���̹Ƿ� queue�� ����)
	bool visited[8][8] = { false, };
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	int infested = virus;

	//���̷��� ��ǥ q�� ����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2) q.push(make_pair(i, j));
		}
	}

	//bfs
	while (!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		//���̷��� �۶߸���
		for (int i = 0; i < 4; i++)		//�� 4�� �������� �����̵�
		{
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
			{
				if (map[next_x][next_y] == 0 && !visited[next_x][next_y])	//��ĭ�̰� �湮���� �ʾҴٸ�
				{
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = true;
					infested++;
				}
			}
		}
	}

	return N * M - (infested + wall + 3);
}

int main(int argc, char* argv[])
{
	int answer = 0;

	cin >> N >> M;		//N : ����ũ��, M : ����ũ��

	//map(������ ����) �Է�
	for (int i = 0; i < N; i++)			//����
	{
		for (int j = 0; j < M; j++)	//����
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) blank.push_back(make_pair(i, j));		//�� ĭ �Է�(����, ����)
			else if (map[i][j] == 1) wall++;
			else if (map[i][j] == 2) virus++;
		}
	}

	//���Ʈ���� �˰���
	for (int i = 0; i < blank.size(); i++)
	{
		for (int j = i + 1; j < blank.size(); j++)
		{
			for (int k = j + 1; k < blank.size(); k++)
			{
				//�������
				map[blank[i].first][blank[i].second] = 1;
				map[blank[j].first][blank[j].second] = 1;
				map[blank[k].first][blank[k].second] = 1;

				answer = max(answer, safe_zone_bfs());

				//�� ����
				map[blank[i].first][blank[i].second] = 0;
				map[blank[j].first][blank[j].second] = 0;
				map[blank[k].first][blank[k].second] = 0;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}