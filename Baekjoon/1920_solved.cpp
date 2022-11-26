#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) 
{
    int N, M;
    vector<int> v;              //입력한 수를 보관할 vector 선언

    cin >> N;

    while (N--)                 //다시 한 번 팁을 쓰자면, 인덱스 직접 접근이 아닌 단순 반복이라면 이게 편할껄~?
    {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());   //vector 내 정렬

    cin >> M;

    while (M--)
    {
        int input;
        scanf("%d", &input);
        cout << binary_search(v.begin(), v.end(), input) << '\n';      //핵심코드 : algorithm 헤더에는 이분 탐색 알고리즘이 포함되어 있다.
    }

    return 0;
}