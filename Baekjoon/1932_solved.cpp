#define _CRT_SECURE_NO_WARNINGS
#define FIND_MAX(x, y) ((x) > (y) ? (x) : (y))

#include <stdio.h>

int main(void)
{
	int size, result = 0;	//�����ﰢ���� ũ��
	scanf("%d", &size);

	int triangle[500][500] = { 0, };
	for (int i = 0; i < size; i++)//�ﰢ���� ����
	{
		for (int j = 0; j < i + 1; j++)//�ش� ���� �ʺ�
		{
			scanf("%d", &triangle[i][j]);
		}
	}
	
	//DP
	for (int i = 1; i < size; i++)
	{
		triangle[i][0] += triangle[i - 1][0];
		for (int j = 1; j < i + 1; j++)
		{
			triangle[i][j] += FIND_MAX(triangle[i - 1][j - 1], triangle[i - 1][j]);
		}
	}
	
	//result
	for (int i = 0; i < size; i++)
	{
		if (result < triangle[size - 1][i]) result = triangle[size - 1][i];
	}
	printf("%d\n", result);

	return 0;
}