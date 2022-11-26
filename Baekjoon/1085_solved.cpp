#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int x, y, w, h;

	cin >> x >> y >> w >> h;

	int shortest;
	if (w - x > x) shortest = x;
	else shortest = w - x;

	if (h - y > y && y < shortest) shortest = y;
	else if (h - y < shortest) shortest = h - y;

	cout << shortest << endl;

	return 0;
}