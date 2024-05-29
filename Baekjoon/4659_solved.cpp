#include <iostream>

using namespace std;

bool isSpellVowel(char letter)
{
	if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
	{
		return true;
	}
	else return false;
}

bool aeiou(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isSpellVowel(str[i]))
		{
			return true;
		}
	}
	return false;
}

bool threeCount(string str)
{
	bool wasLastVowel;
	int count = 1;

	if (isSpellVowel(str[0])) wasLastVowel = true;
	else wasLastVowel = false;

	for (int i = 1; i < str.length(); i++)
	{
		if (isSpellVowel(str[i])) // 모음일때
		{
			if (wasLastVowel) count++;
			else
			{
				wasLastVowel = true;
				count = 1;
			}
		}
		else // 자음일때
		{
			if (wasLastVowel) //마지막이 모음이었다면
			{
				wasLastVowel = false;
				count = 1;
			}
			else count++;
		}
		if (count >= 3) return false;
	}

	return true;
}

bool spellInARow(string str)
{
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			if (str[i] == 'e' || str[i] == 'o') continue;
			else return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	string str = "";
	
	cin >> str;

	while (str != "end")
	{
		if (aeiou(str) && threeCount(str) && spellInARow(str))
		{
			cout << '<' << str << '>' << " is acceptable." << '\n';
		}
		else cout << '<' << str << '>' << " is not acceptable." << '\n';
		
		cin >> str;
	}
	
	return 0;
}