#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int N, high_score = 0;
	scanf("%d", &N);
	int score[1000] = { 0, };

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &score[i]);
		if (score[i] > high_score) high_score = score[i];	//최고점 찾기
	}

	double fixed_score[1000] = { 0, };
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		fixed_score[i] = (double)score[i] / (double)high_score * 100;
		sum += fixed_score[i];
	}

	printf("%lf", sum / N);

	return 0;
}