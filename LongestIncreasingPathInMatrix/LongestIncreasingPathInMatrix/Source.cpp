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

vector<pair<int, int>> GetCandidates(const vector<vector<int>>& a, int r, int c, const unordered_set<string>& visited)
{
	vector<pair<int, int>> res;
	if (r - 1 > 0 && a[r][c] < a[r - 1][c] && visited.find(ToStr(r - 1, c)) == visited.end())
		res.push_back(make_pair(r - 1, c));
	if (c + 1 < a.size() && a[r][c] < a[r][c + 1] && visited.find(ToStr(r, c + 1)) == visited.end())
		res.push_back(make_pair(r, c + 1));
	if (r + 1 < a[r].size() && a[r][c] < a[r + 1][c] && visited.find(ToStr(r + 1, c)) == visited.end())
		res.push_back(make_pair(r + 1, c));
	if (c - 1 >= 0 && a[r][c - 1] && visited.find(ToStr(r, c - 1)) == visited.end())
		res.push_back(make_pair(r, c - 1));
	return res;
}

int LIP(const vector<vector<int>>& a, int r, int c, int maxHere, unordered_set<string>& visited)
{
	int mlen = maxHere;
	auto candidates = GetCandidates(a, r, c, visited);
	for (auto way : candidates)
	{
		string currentCell = ToStr(way.first, way.second);
		visited.insert(currentCell);
		mlen = max(mlen, LIP(a, way.first, way.second, maxHere + 1, visited));
		visited.erase(currentCell);
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
			unordered_set<string> visited;
			visited.insert(ToStr(r, c));
			mlen = max(mlen, LIP(matrix, r, c, 1, visited));
		}
	}

	return mlen;
}

int main()
{
	vector<vector<int>> matrix =
	{
		{3, 4, 5},
		{3, 2, 6},
		{2, 2, 1}
	};

	int len = LongestIncreasingPath(matrix);
	cout << len << endl;
}