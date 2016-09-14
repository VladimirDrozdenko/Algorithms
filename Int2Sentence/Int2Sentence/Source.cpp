#include <iostream>
#include <string>
using namespace std;


string Int2Sentence(int n)
{
	const string ones[] = {
		"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};
	const string tens[] = {
		"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};

	if (n < 0)
		return string("minus") + Int2Sentence(-n);

	string res = {};
	if (n / 1000000) {
		res += Int2Sentence(n / 1000000) + " million";
		n %= 1000000;
	}

	if (n / 1000) {
		res += Int2Sentence(n / 1000) + " thousand";
		n %= 1000;
	}

	if (n / 100) {
		res += Int2Sentence(n / 100) + " hundred";
		n %= 100;
	}

	if (n >= 20) {
		res += " " + tens[n / 10];
		n %= 10;
	}

	if (n > 0) {
		res += " " + ones[n];
	}

	return res;
}

int main()
{
	int n = -4390018;
	cout << n << " ->>>  " << Int2Sentence(n) << endl;
}