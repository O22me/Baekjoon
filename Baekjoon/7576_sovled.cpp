#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000] = { 0, };
queue<pair<int, int> > tomato_q;

int ripebfs(int N, int M)	//����, �ʺ�
{
	int bestripedtomato = 0;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	while (!tomato_q.empty())
	{
		pair<int, int> curr = tomato_q.front();
		tomato_q.pop();

		int x = curr.first;		//����
		int y = curr.second;	//�ʺ�

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];	//����
			int next_y = y + dy[i];	//�ʺ�
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && map[next_x][next_y] == 0)	//�����ȿ� �ִٸ�
			{
				map[next_x][next_y] = map[x][y] + 1;				//�ٽ��ڵ��.	//-1�� �� ���õǴ°�?
				tomato_q.push(make_pair(next_x, next_y));
			}
		}
	}
	//bfs ����

	//�� ���� �丶�� �ִ��� Ȯ�� �� ��¥ �ľ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) return -1;	//�� ���� �丶�䰡 �ִٸ� ��� ���� ���� ��Ȳ
			else if (map[i][j] > bestripedtomato) bestripedtomato = map[i][j];	
		}
	}
	return bestripedtomato - 1;
}

int main(int argc, char* argv[])
{
	int M, N;
	cin >> M >> N;

	for (int i = 0; i < N; i++)			//����
	{
		for (int j = 0; j < M; j++)	//�ʺ�
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) tomato_q.push(make_pair(i, j));
		}
	}
	cout << ripebfs(N, M) << '\n';

	return 0;
}