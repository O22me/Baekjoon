#define _CRT_SECURE_NO_WARNINGS
#define FIND_MAX(x, y) ((x) > (y) ? (x) : (y))
#define MAX 20
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int N;

	cin >> N;	//최대 15

	int dp[MAX] = { 0, };	//dp[i] : i ~ N까지의 최대 보수
	int Ti[MAX] = { 0, };	//소요시간
	int Pi[MAX] = { 0, };	//상담보수

	for (int i = 1; i <= N; i++) cin >> Ti[i] >> Pi[i];

	//DP문제는 뒤에서 접근하는 것이 좋은 방법이 된다.
	for (int j = N; j > 0; j--)
	{
		if (Ti[j] > N - j + 1) dp[j] = dp[j + 1];							//기한 내 할 수 있는 없는 경우
		else dp[j] = FIND_MAX(dp[j + Ti[j]] + Pi[j], dp[j + 1]);	//핵심 : j일에 상담을 진행할 것인가. FIND_MAX(진행, 미진행)
	}

	cout << dp[1] << '\n';

	return 0;
}