#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


string ToStr(int r, int c)
{
	stringstream os;
	os << r << "-" << c;
	return os.str();
}

vector<pair<int, int>> GetCandidates(const vector<vector<int>>& a, int r, int c)
{
	vector<pair<int, int>> res;
	if (r - 1 >= 0 && a[r][c] < a[r - 1][c])
		res.push_back(make_pair(r - 1, c));
	if (c + 1 < a[r].size() && a[r][c] < a[r][c + 1])
		res.push_back(make_pair(r, c + 1));
	if (r + 1 < a.size() && a[r][c] < a[r + 1][c])
		res.push_back(make_pair(r + 1, c));
	if (c - 1 >= 0 && a[r][c] < a[r][c - 1])
		res.push_back(make_pair(r, c - 1));
	return res;
}

int LIP(const vector<vector<int>>& a, int r, int c, int maxHere)
{
	int mlen = maxHere;
	auto candidates = GetCandidates(a, r, c);
	for (auto way : candidates)
	{
		mlen = max(mlen, LIP(a, way.first, way.second, maxHere + 1));
	}

	return mlen;
}

int LongestIncreasingPath(const vector<vector<int>>& matrix)
{
	int mlen = 1;
	for (int r = 0; r < matrix.size(); ++r)
	{
		for (int c = 0; c < matrix[r].size(); ++c)
		{
			mlen = max(mlen, LIP(matrix, r, c, 1));
		}
	}

	return mlen;
}

int main()
{
	const vector<vector<int>> matrix =
	{
		{ 0,  1,   2,  3,  4,  5,  6,  7, 8,  9 },
		{ 19, 18, 17, 16, 15, 14, 13, 12, 0, 10 }
	};

	cout << LongestIncreasingPath(matrix) << endl;
}