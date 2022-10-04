#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void)
{
	int stack[10000] = { 0, };
	int top = -1;
	int T, num;
	scanf("%d", &T);	//명령의 개수

	for (int i = 0; i < T; i++)
	{
		char cmd[6];
		scanf("%s", cmd);
		if (!strcmp(cmd, "push"))
		{
			scanf("%d", &num);
			stack[++top] = num;
		}
		else if (!strcmp(cmd, "pop"))
		{
			if (top == -1) printf("-1\n");		//스택이 빈경우
			else printf("%d\n", stack[top--]);
		}
		else if (!strcmp(cmd, "size")) printf("%d\n", top + 1);
		else if (!strcmp(cmd, "empty"))
		{
			if (top == -1) printf("1\n");			//스택이 비었다면 1
			else printf("0\n");						//스택이 안 비었으면 0
		}
		else if (!strcmp(cmd, "top"))
		{
			if (top == -1) printf("-1\n");		//스택이 빈경우
			else printf("%d\n", stack[top]);
		}
	}

	return 0;
}