#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/*
���ؿ��� ������ �ִ� ����� ���� 100000
maxheap[0]�� Ȱ������ �ʴ´�. ���� 100000 + 1��
*/
int maxheap[100001] = { 0, };
int index;

void heappush(int value)
{
	int curr = index;				//current : push�� �ε��� ��ȣ
	maxheap[index++] = value;

	//��尡 2�� �̻� && �ڽĳ�尡 �θ��庸�� Ŭ ��
	while (curr > 1 && maxheap[curr] > maxheap[curr / 2])
	{
		int temp = maxheap[curr];
		maxheap[curr] = maxheap[curr / 2];
		maxheap[curr / 2] = temp;
		curr /= 2;	//��ȯ �� ���� �ε��� �θ���� �̵�
	}
}

void heappop(int parent)
{
	//��Ʈ���� �ƹ��͵� ���� ���
	if (index == 1)
	{
		printf("0\n");
		return;
	}
	else
	{
		printf("%d\n", maxheap[1]);			//���(�ִ밪)
		maxheap[1] = maxheap[index - 1];	//���� ��带 root�� ��������(delete����)
		index--;
		while (true)
		{
			//��� �ε��� ��ȣ�� �򰥸��� ����.
			int left = parent * 2;			//���� �ڽĳ��
			int right = parent * 2 + 1;	//������ �ڽĳ��
			int largest = parent;			//�θ��尡 ���� ũ�ٰ� ����

			//�θ��带 ������ ���� ū �� ã��
			if (left < index && maxheap[left] > maxheap[largest]) largest = left;
			if (right < index && maxheap[right] > maxheap[largest]) largest = right;
			
			//�θ��尡 ���� ū ���� �ƴ϶��
			if (parent != largest)
			{
				int temp = maxheap[largest];
				maxheap[largest] = maxheap[parent];
				maxheap[parent] = temp;
				//��ȯ �Ŀ��� �θ��尡 ���� ū ��
				parent = largest;
			}
			else break;		//�θ��尡 ���� ū ��� �ݺ��� ����
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