#include <iostream>
#include <vector>
using namespace std;

int FindStart(const vector<int>& a)
{
	int b = 0, e = a.size() - 1;

	while (b <= e)
	{
		int m = b + (e - b) / 2;
		if (m > 0 && a[m - 1] > a[m])
			return m;
		if (m < a.size() - 1 && a[m + 1] < a[m])
			return m + 1;

		if (b == e)
			break;

		if (a[m] < a[e])
			e = m - 1;
		else
			b = m + 1;
	}

	return b; // should never reach this point
}

int main()
{
	vector<vector<int>> a =
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
	};
	
	vector<int> res = {0, 0, 1, 0, 8, 0, 1, 5, 7, 2, 3, 4, 5, 1, 2, 3, 4};

	for (size_t i = 0; i < a.size(); ++i)
	{
		int r = FindStart(a[i]);
		cout << "Case " << i << (r == res[i] ? " PASSED" : " FAILED") << " Result = " << r << " Expected = " << res[i] << endl;
	}
}
