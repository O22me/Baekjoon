#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
    int N, M;
    vector<int> v;              //�Է��� ���� ������ vector ����

    cin >> N;

    while (N--)                 //�ٽ� �� �� ���� ���ڸ�, �ε��� ���� ������ �ƴ� �ܼ� �ݺ��̶�� �̰� ���Ҳ�~?
    {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());   //vector �� ����

    cin >> M;

    while (M--)
    {
        int input;
        scanf("%d", &input);
        cout << binary_search(v.begin(), v.end(), input) << '\n';      //�ٽ��ڵ� : algorithm ������� �̺� Ž�� �˰����� ���ԵǾ� �ִ�.
    }

    return 0;
}