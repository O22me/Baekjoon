#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char* argv[])
{
	int N, K;
	cin >> N >> K;

	int curr;
	int time[100001] = { 0, };
	bool visited[100001] = { false, };
	queue<int> q;

	q.push(N);
	time[N] = 0;
	visited[N] = true;


	while (!q.empty())
	{
		curr = q.front();
		//�ٸ� ��η� ���� �� �����ʴ��İ� ������ �� ������ q���� ���� ���Դٴ°� ���� ���� ��ζ�� ���̴�.
		if (curr == K) break;	
		q.pop();
		if (curr + 1 <= 100000 && (visited[curr + 1] == false || time[curr + 1] > time[curr] + 1))
		{
			visited[curr + 1] = true;
			time[curr + 1] = time[curr] + 1;
			q.push(curr + 1);
		}
		if (curr - 1 >= 0 &&(visited[curr - 1] == false || time[curr - 1] > time[curr] + 1))
		{
			visited[curr - 1] = true;
			time[curr - 1] = time[curr] + 1;
			q.push(curr - 1);
		}
		if (curr * 2 <= 100000 && (visited[curr * 2] == false || time[curr * 2] > time[curr] + 1))
		{
			visited[curr * 2] = true;
			time[curr * 2] = time[curr] + 1;
			q.push(curr * 2);
		}
	}

	cout << time[curr] << '\n';

	return 0;
}