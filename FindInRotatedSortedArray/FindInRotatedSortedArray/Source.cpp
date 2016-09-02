#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int FindInRotatedSortedArray(const vector<int>& a, int val, int b, int e)
{
	if (b > e) return -1;
	if (b == e) return a[b] == val ? b : -1;

	while (b <= e)
	{
		int m = b + (e - b) / 2;
		if (a[m] == val) return m;

		if (a[b] == a[m] && a[m] == a[e])
			return max(FindInRotatedSortedArray(a, val, b, m - 1), FindInRotatedSortedArray(a, val, m + 1, e));

		if (a[b] <= a[m]) // left part of array is sorted
		{
			if (a[b] <= val && a[m] > val)
				e = m - 1;
			else
				b = m + 1;
		}
		else // right part of array is sorted
		{
			if (a[m] < val && a[e] >= val)
				b = m + 1;
			else
				e = m - 1;
		}
	}

	return -1;
}

int main()
{
	/*vector<vector<int>> a =
	{
		{ 1 },
		{ 1, 2 },
		{ 2, 1 },
		{ 1, 2, 3 },
		{ 2, 3, 4, 5, 6, 7, 8, 9, 1 },
		{ 1, 2, 3, 4, 5, 6 },
		{ 7, 1, 2, 3, 4, 5, 6 },
		{ 3, 4, 5, 6, 7, 0, 1, 2 },
		{ 3, 4, 5, 6, 7, 8, 9, 1, 2 },
		{ 10, 11, 3, 4, 5, 6 },
		{ 10, 11, 12, 4, 5, 6 },
		{ 10, 11, 12, 13, 5, 6 },
		{ 10, 11, 12, 13, 14, 6 },
		{ 11, 3, 4, 5, 6 },
		{ 11, 12, 4, 5, 6 },
		{ 11, 12, 13, 5, 6 },
		{ 11, 12, 13, 14, 6 },
	};*/

	int val = 1;
	//vector<int> a = {2, 2, 2, 2, 5, 2, 2};
	vector<int> a = { 0, 1, 2, 2, 2, 2, 2, 2, 2 };
	int r = FindInRotatedSortedArray(a, val, 0, a.size()-1);
	cout << r << endl;
}