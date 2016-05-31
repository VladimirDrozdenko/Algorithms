#include <iostream>
#include <string>
#include <vector>
using namespace std;

// return value:
// 0: reach the end of s but unmatched
// 1: unmatched without reaching the end of s
// 2: matched
int dfs(string& s, string& p, int si, int pi) 
{
	if (si == s.size() && pi == p.size())
		return 2;
	if (si == s.size() && p[pi] != '*')
		return 0;
	if (pi == p.size())
		return 1;

	if (p[pi] == '*')
	{
		if (pi + 1 < p.size() && p[pi + 1] == '*')
			return dfs(s, p, si, pi + 1); // skip duplicate '*'

		for (int i = si; i <= s.size(); ++i)
		{
			int ret = dfs(s, p, i, pi + 1);
			if (ret == 0 || ret == 2) return ret;
		}
	}

	if (p[pi] == '?' || s[si] == p[pi])
		return dfs(s, p, si + 1, pi + 1);
	return 1;
}

bool isMatch(string s, string p)
{
	return dfs(s, p, 0, 0) > 1;
}

void Assert(bool(*func)(string s, string p), string s, string p, bool result)
{
	if (func(s, p) != result)
		cout << "Failed: on \"" << s << "\", \"" << p << "\"" << endl;
	else
		cout << "Success" << endl;
}

int main()
{
	Assert(isMatch, "aa", "a", false);
	Assert(isMatch, "aa", "aa", true);
	Assert(isMatch, "aaa", "aa", false);
	Assert(isMatch, "aa", "*", true);
	Assert(isMatch, "aa", "a*", true);
	Assert(isMatch, "ab", "?*", true);
	Assert(isMatch, "aab", "c*a*b", false);
	Assert(isMatch, "c", "*?*", true);
	Assert(isMatch, "cwer", "*?**", true);
	Assert(isMatch, "cweaar", "*?*a*", true);
	Assert(isMatch, "cwera", "*?*a*", true);
}