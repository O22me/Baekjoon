#include <iostream>
#include <vector>

using namespace std;

struct nodes
{
	char left_child;
	char right_child;
};

vector<nodes> tree(26);

//��ȸ�� �򰥶�� root �������� ���� �ȴ�.
void preorder(char root) //root-left-right
{
	if (root == '.') return;
	//����Լ��� �̿��� ��ȸ
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
	cin >> N;	//����� ���� �Է�

	while (N--)	//Ʈ�� �Է�
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