#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int P;			//테스트 케이스 개수

	cin >> P;

	for (int i = 0; i < P; i++)	//for문을 이용해서 인덱스 활용
	{
		int N, M;		//N : 테스트 케이스 번호	, M : 나머지 피연산자
		int temp, m1 = 0, m2 = 1;
		int count = 0;
		cin >> N >> M;

		while (true)
		{
			if (m1 == 0 && m2 == 1 && count != 0) break;
			//피보나치 수 구하는 과정 : 나머지 연산을 하더라도 n = (n - 2) + (n - 1)은 적용된다.
			temp = m1;
			m1 = m2;
			m2 = (m1 + temp) % M;
			count++;
		}
		cout << N << ' ' << count << '\n';
	}

	return 0;
}