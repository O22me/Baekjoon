#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string str;

	cin >> str;

	int alphabet_frequency[26] = { 0, };
	int max = 0;
	int index[2] = { 0, };
	char result = 'A';

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 97)
		{
			alphabet_frequency[str[i] - 97]++;
		}
		else
		{
			alphabet_frequency[str[i] - 65]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (alphabet_frequency[i] > max)
		{
			max = alphabet_frequency[i];
			index[1] = index[0];
			index[0] = i; // A°¡ ¹®Á¦.
		}
	}

	if (index[0] == index[1])
	{
		cout << "?" << endl;
	}
	else
	{
		result = result + index[0];

		cout << result << endl;
	}

	return 0;
}