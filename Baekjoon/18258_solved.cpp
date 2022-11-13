#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct
{
	int arr[2000001];
	int front, back;
	int size;
}queue;

int main(int argc, char* argv[])
{
	int num_cmd;
	queue q;
	q.front = 0;
	q.back = 0;
	q.size = 0;

	scanf("%d", &num_cmd);

	while (num_cmd--)
	{
		char command[6];
		int input;
		scanf("%s", command);
		//push, pop, size, empty, front, back
		if (!strcmp("push", command))
		{
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
			else printf("%d\n", q.arr[q.front]);
		}
		else if (!strcmp("back", command))
		{
			if (q.size == 0) printf("-1\n");
			else printf("%d\n", q.arr[q.back - 1]);
		}
	}

	return 0;
}