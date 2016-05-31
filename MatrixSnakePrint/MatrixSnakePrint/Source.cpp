#include <iostream>
#include <vector>
using namespace std;

void SnakePrint(const vector<vector<int>>& a)
{
	if (a.empty() || a[0].empty()) return;

	int l = 0, r = a[0].size()-1;
	int u = 0, d = a.size()-1;

	while (l < r && u < d)
	{
		for (int i = l; i < r; ++i)
			cout << a[u][i] << " ";
		for (int i = u; i < d; ++i)
			cout << a[i][r] << " ";
		for (int i = r; i > l; --i)
			cout << a[d][i] << " ";
		for (int i = d; i > u; --i)
			cout << a[i][l] << " ";
		++l;
		--r;
		++u;
		--d;
	}

	if (l == r)
		cout << a[u][l] << " ";
	cout << endl;
}

int main()
{
	/*vector<vector<int>> a = 
	{
		{1,   2,  3,  4,  5},
		{6,   7,  8,  9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};*/

	/*vector<vector<int>> a =
	{
		{  1,  2,  3,  4},
		{  5,  6,  7,  8},
		{  9, 10, 11, 12},
		{ 13, 14, 15, 16}
	};*/

	/*vector<vector<int>> a =
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};*/

	/*vector<vector<int>> a =
	{
		{ 1, 2 },
		{ 3, 4 }
	};*/

	vector<vector<int>> a =
	{
		{ 1 }
	};

	SnakePrint(a);
}