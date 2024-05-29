#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
	int t, sum = 0;
	string test_case, token;

	cin >> t;

	while (t--)
	{
		cin >> test_case;

		stringstream ss(test_case);
		
		while (getline(ss, token, ','))
		{
			sum += stoi(token);
		}

		cout << sum << endl;
		sum = 0;
	}

	return 0;
}