/*
bfs, dfs 두 방법 모두 사용가능하다. 그러나 최단거리를 구하는 문제에서는 bfs를 사용하자.
dfs 는 완전 탐색을 하기 때문에 경로가 많을 수록 시간 복잡도가 커진다.
*/

#include <iostream>
#include <queue>		//bfs를 위한 queue 헤더 추가
#include <algorithm>

using namespace std;

int n, m;
char maze[101][101];					//미로를 저장할 배열
int distance_[101][101];				//각 배열별로 최단거리
bool visited[101][101] = { false, };	//방문하지 않은 곳은 false로 표시

void bfs(int x, int y)	//가로길이, 세로길이
{
	int max = 10001;		//최대거리 10000
	int dx[4] = { 0, 0, -1, 1 };	//2차원 배열에서의 좌표이동을 위한 배열 선언 및 초기화
	int dy[4] = { -1, 1, 0, 0 };

	queue<pair<int, int> > q;	//좌표를 저장하는 queue
	q.push(make_pair(x, y));		//첫 좌표(0, 0) 입력
	visited[x][y] = true;			//방문표시
	distance_[x][y] = 1;
	while (!q.empty())				//queue가 빌 때까지
	{
		pair<int, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = curr.first + dx[i];
			int next_y = curr.second + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)	//큐에 넣을 다음 dx, dy가 n*m 사이에 포함되고 0이상인지
			{
				if (maze[next_x][next_y] == '1' && !visited[next_x][next_y])		//길이있고 방문하지 않은 경우(bfs가 실행되는 경우)
				{
					distance_[next_x][next_y] = distance_[curr.first][curr.second] + 1;	//해당 배열 거리계산 
					visited[next_x][next_y] = true;												//방문표시
					q.push(make_pair(next_x, next_y));											//bfs를 위한 queue푸시
				}
			}
		}
	}
}

int main(int argc, char* argv[])
{
	cin >> n >> m;	//세로길이, 가로길이, n개의 줄에 m개가 포함되어 있음.
	//미로 입력
	for (int i = 0; i < n; i++) cin >> maze[i];

	bfs(0, 0);
	
	cout << distance_[n - 1][m - 1] << endl;	//-1을 빼먹지말자.

	return 0;
}