#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int deque[MAX_SIZE];
int front = 0, rear = 0;
int deque_size = 0;

int main(int argc, char* argv[])
{
	int N;
	scanf("%d", &N);

	while (N--)
	{
		char command[11];
		scanf("%s", command);

		//front는 삽입 후 증가, rear는 증가 후 삽입
		if (!strcmp("push_front", command))
		{
			int input;
			scanf("%d", &input);
			deque[front] = input;
			front = (front - 1 + MAX_SIZE) % MAX_SIZE;
			deque_size++;
		}
		else if (!strcmp("push_back", command))
		{
			int input;
			scanf("%d", &input);
			rear = (rear + 1 + MAX_SIZE) % MAX_SIZE;
			deque[rear] = input;
			deque_size++;
		}
		else if (!strcmp("pop_front", command))
		{
			if (deque_size == 0) printf("-1\n");
			else
			{
				front = (front + 1 + MAX_SIZE) % MAX_SIZE;
				printf("%d\n", deque[front]);
				deque_size--;
			}
		}
		else if (!strcmp("pop_back", command))
		{
			if (deque_size == 0) printf("-1\n");
			else
			{
				printf("%d\n", deque[rear]);
				rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
				deque_size--;
			}
		}
		else if (!strcmp("size", command))
		{
			printf("%d\n", deque_size);
		}
		else if (!strcmp("empty", command))
		{
			if (deque_size == 0) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp("front", command))
		{
			if (deque_size == 0) printf("-1\n");
			else
			{
				printf("%d\n", deque[(front + 1 + MAX_SIZE) % MAX_SIZE]);	//중요!
			}
		}
		else if (!strcmp("back", command))
		{
			if (deque_size == 0) printf("-1\n");
			else
			{
				printf("%d\n", deque[rear]);
			}
		}
	}

	return 0;
}