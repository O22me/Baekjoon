#include <iostream>
#include <vector>

using namespace std;

vector<int> Position;
int N, M;

bool IsPossible(int height)
{
	int brightRightMax = 0;

	for (int curr : Position)
	{
		int leftBright = curr - height;
		int rightBright = curr + height;

		if (leftBright > brightRightMax) return false;

		brightRightMax = rightBright;
	}

	if (brightRightMax < N) return false;
	else return true;
}

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	while (M--)
	{
		int pos;
		
		cin >> pos;

		Position.push_back(pos);
	}

	int low = 0;
	int high = N;
	int mid = (low + high) / 2;

	while (low != high)
	{
		if ((high - low) <= 1)
		{
			if (IsPossible(high))
			{
				low = high;
			}
			else high = low;

			break;
		}

		if (IsPossible(mid))
		{
			high = mid;
			mid = (low + high) / 2;
		}
		else
		{
			low = mid;
			mid = (low + high) / 2;
		}
	}

	cout << low;

	return 0;
}