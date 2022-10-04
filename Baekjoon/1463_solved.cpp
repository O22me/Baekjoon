#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#define FIND_MIN(x, y) ((x) > (y) ? (y) : (x))

#include <stdio.h>
int main(void)
{
	int input;
	scanf("%d", &input);
	int memo[MAX];

	memo[0] = 0;
	memo[1] = 0;
	for (int i = 2; i < MAX; i++)
	{
		memo[i] = memo[i - 1] + 1; // -1�ϴ� ���
		if (i % 3 == 0) //3���� ���� �� �ִٸ�
		{
			memo[i] = FIND_MIN(memo[i], memo[i / 3] + 1);
		}
		if (i % 2 == 0) //2�� ���� �� �ִٸ�
		{
			memo[i] = FIND_MIN(memo[i], memo[i / 2] + 1);
		}
	}
	printf("%d ", memo[input]);

	return 0;
}