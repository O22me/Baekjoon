#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char* argv[])
{
	queue<int> q;
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) q.push(i);	//1~N까지 Push

	printf("<");

	while (q.size() > 1)
	{
		for (int i = 1; i < K; i++)	//K - 1만큼 반복
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}

	printf("%d>\n", q.front());

	return 0;
}