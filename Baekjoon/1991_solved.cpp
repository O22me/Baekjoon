#include <iostream>
#include <vector>

using namespace std;

struct nodes
{
	char left_child;
	char right_child;
};

vector<nodes> tree(26);

//순회가 헷갈라면 root 기준으로 보면 된다.
void preorder(char root) //root-left-right
{
	if (root == '.') return;
	//재귀함수를 이용한 순회
	cout << root;
	preorder(tree[root - 'A'].left_child);
	preorder(tree[root - 'A'].right_child);
}

void inorder(char root)	//left-root-right
{
	if (root == '.') return;
	inorder(tree[root - 'A'].left_child);
	cout << root;
	inorder(tree[root - 'A'].right_child);
}

void postorder(char root)	//left-right-root
{
	if (root == '.') return;
	postorder(tree[root - 'A'].left_child);
	postorder(tree[root - 'A'].right_child);
	cout << root;
}

int main(int argc, char* argv[])
{
	int N;
	cin >> N;	//노드의 개수 입력

	while (N--)	//트리 입력
	{
		char root, left, right;
		cin >> root >> left >> right;
		tree[root - 'A'].left_child = left;
		tree[root - 'A'].right_child = right;
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');

	return 0;
}