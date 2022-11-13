#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct
{
	int arr[10001];
	int front, back, size;
}queue;

int main(int argc, char* argv[])
{
	int cmd_num;
	queue q;

	//큐 초기화
	q.front = 0;
	q.back = 0;
	q.size = 0;

	scanf("%d", &cmd_num);

	while (cmd_num--)
	{
		char command[6];
		scanf("%s", command);

		if (!strcmp("push", command))
		{
			int input;
			scanf("%d", &input);
			q.arr[q.back++] = input;
			q.size++;
		}
		else if (!strcmp("pop", command))
		{
			if (q.size == 0) printf("-1\n");
			else
			{
				printf("%d\n", q.arr[q.front++]);
				q.size--;
			}
		}
		else if (!strcmp("size", command)) printf("%d\n", q.size);
		else if (!strcmp("empty", command))
		{
			if (q.size == 0) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp("front", command))
		{
			if (q.size == 0) printf("-1\n");
			else
			{
				printf("%d\n", q.arr[q.front]);
			}
		}
		else if (!strcmp("back", command))
		{
			if (q.size == 0) printf("-1\n");
			else
			{
				printf("%d\n", q.arr[q.back - 1]);
			}
		}
	}

	return 0;
}