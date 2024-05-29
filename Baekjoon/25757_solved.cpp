#include <iostream>
#include <set>

using namespace std;

int main(int argc, char* argv[])
{
	int N;
	char game;
	set<string> applier;

	cin >> N >> game;

	while (N--)
	{
		string str;
		cin >> str;

		applier.insert(str);
	}

	if (game == 'Y')
	{
		cout << applier.size() << '\n';
	}
	else if (game == 'F')
	{
		cout << applier.size() / 2 << '\n';
	}
	else if (game == 'O')
	{
		cout << applier.size() / 3 << '\n';
	}

	return 0;
}