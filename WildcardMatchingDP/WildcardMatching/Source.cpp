#include <iostream>
#include <string>
#include <vector>
using namespace std;

string RemoveDups(const string& p)
{
	string out;
	for (size_t i = 0; i < p.size();)
	{
		out += p[i];
		if (p[i] == '*')
			while (p[++i] == '*') out += p[i];
		else
			++i;
	}
	return out;
}

bool IsMatch(const string& s, const string& p)
{
	string pp = RemoveDups(p);

	const size_t ssize = s.size() + 1;
	const size_t psize = pp.size() + 1;

	vector<vector<bool>> T(ssize);
	for (size_t i = 0; i < s.size() + 1; ++i)
		T[i].resize(psize);
	T[0][0] = true;
	T[0][1] = pp[0] == '*';
	
	for (size_t r = 1; r < ssize; ++r)
	{
		for (size_t c = 1; c < psize; ++c)
		{
			if (p[c - 1] == '*')
				T[r][c] = T[r][c - 1] || T[r - 1][c];
			else if (p[c - 1] == s[r - 1] || p[c - 1] == '?')
				T[r][c] = T[r - 1][c - 1];
			else
				T[r][c] = false;
		}
	}

	return T[ssize-1][psize-1];
}

void Assert(bool(*func)(const string&, const string&), string s, string p, bool result)
{
	if (func(s, p) != result)
		cout << "Failed: on \"" << s << "\", \"" << p << "\"" << endl;
	else
		cout << "Success" << endl;
}

int main()
{
	Assert(IsMatch, "aa", "a", false);
	Assert(IsMatch, "aa", "aa", true);
	Assert(IsMatch, "aaa", "aa", false);
	Assert(IsMatch, "aa", "*", true);
	Assert(IsMatch, "aa", "a*", true);
	Assert(IsMatch, "ab", "?*", true);
	Assert(IsMatch, "aab", "c*a*b", false);
}