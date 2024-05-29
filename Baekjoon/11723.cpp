#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	string cmd;
	int number;
	bool set[21] = { false, };

	cin >> m;

	while (m--)
	{
		cin >> cmd;

		if (cmd == "add")
		{
			cin >> number;
			set[number] = true;
		}
		else if (cmd == "remove")
		{
			cin >> number;
			set[number] = false;
		}
		else if (cmd == "check")
		{
			cin >> number;
			cout << set[number] << endl;
		}
		else if (cmd == "toggle")
		{
			cin >> number;
			set[number] = !set[number];
		}
		else if (cmd == "all")
		{
			for (int i = 1; i < 21; i++)
			{
				set[i] = true;
			}
		}
		else if (cmd == "empty")
		{
			for (int i = 1; i < 21; i++)
			{
				set[i] = false;
			}
		}
	}

	return 0;
}