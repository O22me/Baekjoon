#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int dp[46];	//0~45번째까지 출력해야하므로 총 46개 크기의 배열이 필요.

	cin >> n;		//n 입력

	dp[0] = 0;	//dp의 초기값을 정해줘야 한다.
	dp[1] = 1;

	for (int i = 2; i <= n; i++)			//인덱스 = n으로 사용할 것이므로
	{
		dp[i] = dp[i - 2] + dp[i - 1];		//점화식
	}

	cout << dp[n] << '\n';				//출력 : endl보단 '\n'을 사용하는 것이 빠르다.

	return 0;
}