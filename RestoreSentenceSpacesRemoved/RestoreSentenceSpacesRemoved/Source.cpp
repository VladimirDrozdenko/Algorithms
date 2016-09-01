#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> dict = {
	"a",
	"is",
	"str",
	"broken",
	"string",
	"this",
	"fuck",
	"fucking",
	"ring",
	"isis"
};


bool RestoreSentenceWithMissing(const string& sentence, size_t pos, vector<string>& words)
{
	if (pos == sentence.size())
	{
		copy(words.begin(), words.end(), ostream_iterator<string>(cout, " "));
		cout << endl;
		return true;
	}

	for (size_t i = pos + 1; i <= sentence.size(); ++i)
	{
		string w = sentence.substr(pos, i - pos);
		if (dict.find(w) != dict.end())
		{
			words.push_back(w);
			if (!RestoreSentenceWithMissing(sentence, i, words))
				words.pop_back();
		}
	}

	return false;
}

int main()
{
	string sentence = "thisisabrokenfuckingstring";

	RestoreSentenceWithMissing(sentence, 0, vector<string>());
}