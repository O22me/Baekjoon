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
	heap.tree[1] = heap.tree[heap.leaf_pos - 1];	//delete 연산
	heap.leaf_pos--;
	int parent = 1;
	while (parent < heap.leaf_pos)
	{
		int left = parent * 2;
		int right = parent * 2 + 1;
		int smallest = parent;
		//가장 작은 값을 가지는 노드를 찾는과정
		if (left < heap.leaf_pos && heap.tree[left] < heap.tree[smallest])
		{
			smallest = left;
		}
		if (right < heap.leaf_pos && heap.tree[right] < heap.tree[smallest])
		{
			smallest = right;
		}

		if (parent != smallest)		//부모노드가 가장 작은 value를 가진 노드가 아니라면 교체
		{
			int temp = heap.tree[parent];
			heap.tree[parent] = heap.tree[smallest];
			heap.tree[smallest] = temp;
			//바꿨다면
			parent = smallest;
		}
		else return;
	}
}
*/

/* 재귀를 이용한 정렬 : 시간초과 */
void heapsort(int parent)
{
	if (parent * 2 >= leaf_pos) return;		//자식 노드가 없으면 종료
	int left = parent * 2;
	int right = parent * 2 + 1;
	int smallest = parent;
	//가장 작은 값을 가지는 노드를 찾는과정
	if (left < leaf_pos && tree[left] < tree[smallest])
	{
		smallest = left;
	}
	if (right < leaf_pos && tree[right] < tree[smallest])
	{
		smallest = right;
	}

	if (smallest != parent)		//자식노드에 현재 노드보다 작은게 있다면
	{
		int temp = tree[parent];
		tree[parent] = tree[smallest];
		tree[smallest] = temp;
		heapsort(smallest);
	}
	else return;
}

/*
이번 문제를 풀면서..
잦은 입출력를 요구하는 알고리즘에서 cout, cin 등의 사용은 지양하자.
아니면 
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL)
를 사용해서 속도를 높여야겠다.
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
				printf("0\n");	//트리가 비어있다면 0을 출력
			}
			else
			{
				//heappop();
				/*
				*/
				printf("%d\n", tree[1]);				//root 출력(최솟값)
				tree[1] = tree[leaf_pos - 1];	//말단 노드 가져와서 root에 덮어쓰기
				heapsort(1);											//힙정렬
				leaf_pos--;									
			}
		}
		else heappush(input);
	}

	return 0;
}