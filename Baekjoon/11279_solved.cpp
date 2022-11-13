#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/*
백준에서 제시한 최대 명령의 개수 100000
maxheap[0]은 활용하지 않는다. 따라서 100000 + 1개
*/
int maxheap[100001] = { 0, };
int index;

void heappush(int value)
{
	int curr = index;				//current : push될 인덱스 번호
	maxheap[index++] = value;

	//노드가 2개 이상 && 자식노드가 부모노드보다 클 때
	while (curr > 1 && maxheap[curr] > maxheap[curr / 2])
	{
		int temp = maxheap[curr];
		maxheap[curr] = maxheap[curr / 2];
		maxheap[curr / 2] = temp;
		curr /= 2;	//교환 후 현재 인덱스 부모노드로 이동
	}
}

void heappop(int parent)
{
	//힙트리에 아무것도 없을 경우
	if (index == 1)
	{
		printf("0\n");
		return;
	}
	else
	{
		printf("%d\n", maxheap[1]);			//출력(최대값)
		maxheap[1] = maxheap[index - 1];	//말단 노드를 root로 데려오기(delete연산)
		index--;
		while (true)
		{
			//모두 인덱스 번호다 헷갈리지 말자.
			int left = parent * 2;			//왼쪽 자식노드
			int right = parent * 2 + 1;	//오른쪽 자식노드
			int largest = parent;			//부모노드가 가장 크다고 가정

			//부모노드를 포함한 가장 큰 값 찾기
			if (left < index && maxheap[left] > maxheap[largest]) largest = left;
			if (right < index && maxheap[right] > maxheap[largest]) largest = right;
			
			//부모노드가 가장 큰 값이 아니라면
			if (parent != largest)
			{
				int temp = maxheap[largest];
				maxheap[largest] = maxheap[parent];
				maxheap[parent] = temp;
				//교환 후에는 부모노드가 가장 큰 값
				parent = largest;
			}
			else break;		//부모노드가 가장 큰 경우 반복문 종료
		}
	}
	return;
}

int main(int argc, char* argv[])
{
	int N;

	scanf("%d", &N);
	index = 1;

	while (N--)
	{
		int input;
		scanf("%d", &input);

		if (input == 0) heappop(1);
		else heappush(input);
	}

	return 0;
}