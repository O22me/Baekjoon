#include <iostream>

using namespace std;

int tree[100001] = { 0, };
int leaf_pos;

void heappush(int value)
{
	tree[leaf_pos++] = value;
	int curr = leaf_pos - 1;
	while (tree[curr] < tree[curr / 2] && curr != 1)
	{
		int temp = tree[curr / 2];
		tree[curr / 2] = tree[curr];
		tree[curr] = temp;
		curr /= 2;
	}
}
/*
void heappop()
{
	cout << heap.tree[1] << '\n';
	heap.tree[1] = heap.tree[heap.leaf_pos - 1];	//delete ����
	heap.leaf_pos--;
	int parent = 1;
	while (parent < heap.leaf_pos)
	{
		int left = parent * 2;
		int right = parent * 2 + 1;
		int smallest = parent;
		//���� ���� ���� ������ ��带 ã�°���
		if (left < heap.leaf_pos && heap.tree[left] < heap.tree[smallest])
		{
			smallest = left;
		}
		if (right < heap.leaf_pos && heap.tree[right] < heap.tree[smallest])
		{
			smallest = right;
		}

		if (parent != smallest)		//�θ��尡 ���� ���� value�� ���� ��尡 �ƴ϶�� ��ü
		{
			int temp = heap.tree[parent];
			heap.tree[parent] = heap.tree[smallest];
			heap.tree[smallest] = temp;
			//�ٲ�ٸ�
			parent = smallest;
		}
		else return;
	}
}
*/

/* ��͸� �̿��� ���� : �ð��ʰ� */
void heapsort(int parent)
{
	if (parent * 2 >= leaf_pos) return;		//�ڽ� ��尡 ������ ����
	int left = parent * 2;
	int right = parent * 2 + 1;
	int smallest = parent;
	//���� ���� ���� ������ ��带 ã�°���
	if (left < leaf_pos && tree[left] < tree[smallest])
	{
		smallest = left;
	}
	if (right < leaf_pos && tree[right] < tree[smallest])
	{
		smallest = right;
	}

	if (smallest != parent)		//�ڽĳ�忡 ���� ��庸�� ������ �ִٸ�
	{
		int temp = tree[parent];
		tree[parent] = tree[smallest];
		tree[smallest] = temp;
		heapsort(smallest);
	}
	else return;
}

/*
�̹� ������ Ǯ�鼭..
���� ����¸� �䱸�ϴ� �˰��򿡼� cout, cin ���� ����� ��������.
�ƴϸ� 
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL)
�� ����ؼ� �ӵ��� �����߰ڴ�.
*/

int main(int argc, char* argv[])
{
	int N;
	leaf_pos = 1;

	scanf("%d", &N);

	while (N--)
	{
		int input;
		scanf("%d", &input);

		if (input == 0)
		{
			if (leaf_pos == 1)
			{
				printf("0\n");	//Ʈ���� ����ִٸ� 0�� ���
			}
			else
			{
				//heappop();
				/*
				*/
				printf("%d\n", tree[1]);				//root ���(�ּڰ�)
				tree[1] = tree[leaf_pos - 1];	//���� ��� �����ͼ� root�� �����
				heapsort(1);											//������
				leaf_pos--;									
			}
		}
		else heappush(input);
	}

	return 0;
}