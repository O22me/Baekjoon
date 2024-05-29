#include <iostream>

using namespace std;

char oven[1000][1000];

void cookie(int N)
{
	for (int i = 0; i < N; i++)		// За
	{
		for (int j = 0; j < N; j++)	// ї­
		{
			cin >> oven[i][j];
		}
	}
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, heartX = 0, heartY = 0;
	int leftArm = 0, rightArm = 0, waist = 0, leftLeg = 0, rightLeg = 0;
	int WaistEnd;

	cin >> N;

	cookie(N);

	// find heart position.
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (oven[i][j + 1] == '*' && oven[i][j - 1] == '*' && oven[i + 1][j] == '*' && oven[i - 1][j] == '*')
			{
				heartX = j;
				heartY = i;
				cout << i + 1 << " " << j + 1 << '\n';
			}
		}
	}

	// Left Arm
	for (int j = heartX - 1; j >= 0 && oven[heartY][j] == '*'; j--)
	{
		leftArm++;
	}
	cout << leftArm << ' ';

	// Right Arm
	for (int j = heartX + 1; j < N && oven[heartY][j] == '*'; j++)
	{
		rightArm++;
	}
	cout << rightArm << ' ';

	// Waist
	for (int i = heartY + 1; i < N && oven[i][heartX] == '*'; i++)
	{
		waist++;
		WaistEnd = i + 1;
	}
	cout << waist << ' ';

	// Left Leg
	for (int i = WaistEnd; i < N && oven[i][heartX - 1] == '*'; i++)
	{
		leftLeg++;
	}
	cout << leftLeg++ << ' ';

	// Right Leg
	for (int i = WaistEnd; i < N && oven[i][heartX + 1] == '*'; i++)
	{
		rightLeg++;
	}
	cout << rightLeg++;

	return 0;
}