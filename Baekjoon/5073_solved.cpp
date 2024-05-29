#include <iostream>

using namespace std;

int main(int argc, char* argv)
{
	int side1, side2, side3;
	int longest;

	cin >> side1 >> side2 >> side3;

	while (true)
	{
		longest = 0;

		if (side1 == 0 && side2 == 0 && side3 == 0) break;

		if (side1 == 0 || side2 == 0 || side3 == 0)
		{
			cout << "Invalid" << endl;
		}

		if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2)
		{
			cout << "Invalid" << endl;
		}
		else
		{
			if (side1 == side2 && side2 == side3) cout << "Equilateral" << endl;
			else if (side1 == side2 || side2 == side3 || side1 == side3) cout << "Isosceles" << endl;
			else cout << "Scalene" << endl;
		}

		cin >> side1 >> side2 >> side3;
	}
	
	return 0;
}