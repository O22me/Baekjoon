#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

bool field[51][51] = { false, };	//bool 배열 false로 자동 초기화.
bool visited[51][51] = { false, };

void dfs(int x, int y, int n, int m)
{
	visited[x][y] = true;
	//상하좌우의 dfs를 진행해야함.
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	//4가지 방향
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (x >= 0 && x < n && y >= 0 && y < m)	//(x, y)의 좌표가 배추밭안에 위치하는지
		{
			if (field[nx][ny] && !visited[nx][ny]) dfs(nx, ny, n, m);	//재귀를 이용한 dfs
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
		int m, n, k;//m은 가로길이, n은 세로길이
		cin >> m >> n >> k;
		//field : 배추가 심어진 밭, visited : 그래프 순환을 위한 방문 노드 표시
		while (k--)	//배추가 심어져 있는 위치값 입력
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = true;	//y는 세로길이, x는 가로길이
		}
		//각 field를 돌면서 배추 발견시 dfs실행을 통한 visited 배열 수정
		for (int i = 0; i < n; i++)			//i : 세로
		{
			for (int j = 0; j < m; j++)	//j : 가로
			{
				if (field[i][j] && !visited[i][j])	//새로운 그룹(배추) 발견
				{
					group++;
					dfs(i, j, n, m);
				}
			}
		}
		cout << group << endl;
		//다음 테스트 케이스를 위한 초기화
		memset(visited, false, sizeof(visited));
		memset(field, false, sizeof(field));
	}

	return 0;
}