#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int FindWaterAmount(const int* a, int n)
{
	vector<int> left(n);
	left[0] = a[0];
	for (int i = 1; i < n; ++i)
		left[i] = max(left[i - 1], a[i]);

	vector<int> right(n);
	right[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i)
		right[i] = max(right[i + 1], a[i]);

	int water = 0;
	for (int i = 0; i < n; ++i)
		water += max(min(left[i], right[i]) - a[i], 0);
	return water;
}

int main()
{
	//int a[] = {0, 1, 2, 1, 4, 3, 0, 1, 2, 2, 0, 1, 1};
	int a[] = { 1, 2, 3, 4, 1, 2, 2, 1 };
	const int n = sizeof(a) / sizeof(*a);

	cout << "Watter amount to hold: " << FindWaterAmount(a, n) << endl;
}