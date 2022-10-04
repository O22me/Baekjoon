#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int test_case = 0;
	scanf("%d", &test_case);

	int x1, y1, r1, x2, y2, r2;
	double distance = 0;

	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		distance = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
		int subtract = r1 > r2 ? r1 - r2 : r2 - r1;

		if (distance == 0 && r1 == r2)	//두 원이 겹침
		{
			printf("-1\n");
		}
		else if (distance < (r1 + r2) && (subtract < distance))
		{
			printf("2\n");
		}
		else if (distance == (r1 + r2) || (subtract == distance))
		{
			printf("1\n");
		}
		else printf("0\n");
	}

	return 0;
}