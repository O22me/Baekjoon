#include <iostream>
#include <math.h>
#include <memory.h>		//memset

using namespace std;

bool isprime[1000001];

int main(int argc, char* argv[])
{
	int m, n;				//m이상 n이하의 소수구하기

	cin >> m >> n;

	memset(isprime, true, sizeof(isprime));		//isprime 배열을 true로 처리한다음, false로 걸러내는 작업

	isprime[0] = false;	//0과 1은 소수가 아니다.
	isprime[1] = false;
	
	//내가 생각하기에는 2(짝수)와 3까지는 사전 작업으로 조금 더 속도를 줄일 수도 있을 것이다.
	for (int i = 2; i <= sqrt(n); i++)	//에라토스테네스의 체 : 모든 범위의 수에 대해 배수 제외 처리를 하지 않아 빠르다..!
	{
		for (int j = i * 2; j <= n; j += i)	//i 의 배수부터 시작해야 한다. 즉, j는 i의 배수로 작용한다.
		{
			if (j % i == 0) isprime[j] = false;	//나누어 떨어지면 소수가 아니다.
		}
	}

	for (int i = m; i <= n; i++)	//출력
	{
		if (isprime[i]) cout << i << '\n';
	}

	return 0;
}