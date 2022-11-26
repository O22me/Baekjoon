#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000] = { 0, };
queue<pair<int, int> > tomato_q;

int ripebfs(int N, int M)	//높이, 너비
{
	int bestripedtomato = 0;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	while (!tomato_q.empty())
	{
		pair<int, int> curr = tomato_q.front();
		tomato_q.pop();

		int x = curr.first;		//높이
		int y = curr.second;	//너비

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];	//높이
			int next_y = y + dy[i];	//너비
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && map[next_x][next_y] == 0)	//지도안에 있다면
			{
				map[next_x][next_y] = map[x][y] + 1;				//핵심코드다.	//-1이 왜 무시되는가?
				tomato_q.push(make_pair(next_x, next_y));
			}
		}
	}
	//bfs 종료

	//안 익은 토마토 있는지 확인 및 날짜 파악
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) return -1;	//안 익은 토마토가 있다면 모두 익지 못한 상황
			else if (map[i][j] > bestripedtomato) bestripedtomato = map[i][j];	
		}
	}
	return bestripedtomato - 1;
}

int main(int argc, char* argv[])
{
	int M, N;
	cin >> M >> N;

	for (int i = 0; i < N; i++)			//높이
	{
		for (int j = 0; j < M; j++)	//너비
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) tomato_q.push(make_pair(i, j));
		}
	}
	cout << ripebfs(N, M) << '\n';

	return 0;
}