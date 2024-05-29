#include <iostream>

using namespace std;

int main(int argc, char* argv)
{
	int h, w, n, m;
	int count_h, count_w;

	cin >> h >> w >> n >> m;

	if (h % (n + 1) != 0)
	{
		count_h = (h / (n + 1)) + 1;
	}
	else count_h = h / (n + 1);

	if (w % (m + 1) != 0)
	{
		count_w = (w / (m + 1)) + 1;
	}
	else count_w = w / (m + 1);

	cout << count_h * count_w << endl;

	return 0;
}