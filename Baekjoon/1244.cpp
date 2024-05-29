#include <iostream>
#include <queue>

using namespace std;

int Switch[100];
queue<pair<int, int> > students;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, student;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> Switch[i];
	}

	cin >> student;

	for (int i = 0; i < student; i++)
	{
		pair<int, int> execute;
		cin >> execute.first >> execute.second;
		students.push(execute);
	}

	while (!students.empty())
	{
		if (students.front().first == 1)	// 남학생
		{
			int number = students.front().second;
			for (int i = number - 1; i < n; i += number)
			{
				Switch[i] = ~Switch[i];
			}
		}
		else if (students.front().first == 2)	// 여학생
		{
			int number = students.front().second;
			Switch[number - 1] = ~Switch[number - 1];
			for (int i = 1; Switch[number - i - 1] == Switch[number + i - 1]; i++)
			{
				if (number + i - 1 > n || number - i - 1 < 0) break;
				Switch[i - 1] = ~Switch[i - 1];
				Switch[i + 1] = ~Switch[i + 1];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << Switch[i] << ' ';
		if (i % 20 == 0)
		{
			cout << '\n';
		}
	}

	return 0;
}