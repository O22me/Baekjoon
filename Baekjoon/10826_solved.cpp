#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string sum(string x, string y)
{
	int num, carry = 0;
	string result = "";

	//���ڸ� ���� ����ؾ������� �������ش�.
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	while (x.length() > y.length())	//x�� y���� ��ٸ�
	{
		y += '0';							//���ڸ��� 0�߰�
	}

	while (x.length() < y.length())
	{
		x += '0';		//���� ����
	}

	for (int i = 0; i < x.length(); i++)
	{
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;	//�������� ���ڿ��� �� ���ڸ� ���(������ ���)
		result += to_string(num);						//int->string���� ��ȯ�� result�� �߰�
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;	//���� ���� �ڸ����� ������
	}
	if (carry != 0) result += to_string(carry);			//��� �Ϸ� �� ���� ���� ���� ������ �ڸ��� �߰�.

	reverse(result.begin(), result.end());

	return result;
}

int main(int argc, char* argv[])
{
	int n;
	string dp[10001];	//�ʹ� ũ�� �����÷ο찡 �߻��Ѵ� : ���ڿ� ó���Ѵ�.

	cin >> n;		//n �Է�

	dp[0] = '0';	//dp�� �ʱⰪ�� ������� �Ѵ�.
	dp[1] = '1';	//���ڿ��ӿ� Ȯ���϶�.

	for (int i = 2; i <= n; i++)			//�ε��� = n���� ����� ���̹Ƿ�
	{
		dp[i] = sum(dp[i - 2], dp[i - 1]);		//��ȭ��
	}

	cout << dp[n] << '\n';				//��� : endl���� '\n'�� ����ϴ� ���� ������.

	return 0;
}