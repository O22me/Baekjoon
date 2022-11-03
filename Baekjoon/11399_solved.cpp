#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int N, total = 0, temp = 0; //줄을 서는 사람의 수
	vector<int> waiting_time;	//기다리는 시간을 저장하는 vector 선언

	cin >> N;

	while (N--)	//사람수만큼 입력
	{
		int time;
		cin >> time;
		waiting_time.push_back(time);
	}

	sort(waiting_time.begin(), waiting_time.end()); //그리디 알고리즘을 위한 정렬

	for (int i = 0; i < waiting_time.size(); i++)
	{
		temp += waiting_time[i];
		total += temp;
	}

	cout << total;

	return 0;
}