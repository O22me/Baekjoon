#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int dp[46];	//0~45��°���� ����ؾ��ϹǷ� �� 46�� ũ���� �迭�� �ʿ�.

	cin >> n;		//n �Է�

	dp[0] = 0;	//dp�� �ʱⰪ�� ������� �Ѵ�.
	dp[1] = 1;

	for (int i = 2; i <= n; i++)			//�ε��� = n���� ����� ���̹Ƿ�
	{
		dp[i] = dp[i - 2] + dp[i - 1];		//��ȭ��
	}

	cout << dp[n] << '\n';				//��� : endl���� '\n'�� ����ϴ� ���� ������.

	return 0;
}