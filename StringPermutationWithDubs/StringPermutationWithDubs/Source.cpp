#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

bool IsZeroed(const vector<size_t>& v)
{
	for (auto a : v)
		if (a != 0) return false;
	return true;
}

void Perm(const string& in, size_t level, vector<size_t> cnt, string& res)
{
	if (IsZeroed(cnt))
	{
		cout << res << endl;
		return;
	}

	for (size_t i = 0; i < in.size(); ++i)
	{
		if (cnt[i] == 0) continue;
		res[level] = in[i];
		--cnt[i];
		Perm(in, level + 1, cnt, res);
		++cnt[i];
	}
}

void Perm(const string& s)
{
	string res(s.size(), ' ');
	unordered_map<char, size_t> table;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (table.find(s[i]) == table.end())
			table.insert(make_pair(s[i], 0));
		++table[s[i]];
	}

	string in = "";
	vector<size_t> cnt;

	size_t i = 0;
	for (pair<char, size_t> p : table)
	{
		in += p.first;
		cnt.push_back(p.second);
	}

	Perm(in, 0, cnt, res);
}

int main()
{
	string s = "abbcddddddd";
	Perm(s);
}
