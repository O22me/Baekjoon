#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string sum(string x, string y)
{
	int num, carry = 0;
	string result = "";

	//뒷자리 부터 계산해야함으로 뒤집어준다.
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	while (x.length() > y.length())	//x가 y보다 길다면
	{
		y += '0';							//뒷자리에 0추가
	}

	while (x.length() < y.length())
	{
		x += '0';		//위와 동일
	}

	for (int i = 0; i < x.length(); i++)
	{
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;	//뒤집어진 문자열의 맨 앞자리 계산(나머지 계산)
		result += to_string(num);						//int->string으로 변환후 result에 추가
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;	//몫은 다음 자리수로 가야함
	}
	if (carry != 0) result += to_string(carry);			//계산 완료 후 다음 몫은 제일 마지막 자리에 추가.

	reverse(result.begin(), result.end());

	return result;
}

int main(int argc, char* argv[])
{
	int n;
	string dp[10001];	//너무 크면 오버플로우가 발생한다 : 문자열 처리한다.

	cin >> n;		//n 입력

	dp[0] = '0';	//dp의 초기값을 정해줘야 한다.
	dp[1] = '1';	//문자열임에 확인하라.

	for (int i = 2; i <= n; i++)			//인덱스 = n으로 사용할 것이므로
	{
		dp[i] = sum(dp[i - 2], dp[i - 1]);		//점화식
	}

	cout << dp[n] << '\n';				//출력 : endl보단 '\n'을 사용하는 것이 빠르다.

	return 0;
}