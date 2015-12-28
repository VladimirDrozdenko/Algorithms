#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

vector<size_t> coinChangeWithTracking(vector<size_t>& coins, size_t amount)
{
	const size_t infinity = (size_t)-1;
	if (amount == 0)
		return vector<size_t>();

	sort(coins.begin(), coins.end());

	vector<size_t> coinTracker(amount + 1);
	vector<size_t> min_arr(amount + 1, infinity);
	coinTracker[0] = 0;
	min_arr[0] = 0;

	for (size_t i = 1; i <= amount; ++i)
	{
		for (size_t c = 0; c < coins.size(); ++c)
		{
			if (coins[c] > i)
				break;

			if (min_arr[i - coins[c]] != infinity)
			{
				if (min_arr[i] > min_arr[i - coins[c]] + 1)
				{
					min_arr[i] = min_arr[i - coins[c]] + 1;
					coinTracker[i] = coins[c];
				}
			}
		}
	}

	if (min_arr[amount] == 0 || min_arr[amount] == infinity)
		return vector<size_t>();

	vector<size_t> result;
	while (amount > 0)
	{
		size_t coin = coinTracker[amount];
		result.push_back(coin);
		amount -= coin;
	}

	return result;
}

string toString(size_t n)
{
	stringstream os;
	os << n;
	return os.str();
}

int main()
{
	vector<size_t> coins = { 3, 5 };
	cout << "Available coins: { ";
	copy(coins.begin(), coins.end(), ostream_iterator<size_t>(cout, " "));
	cout << "}\n" << endl;

	for (size_t amount = 0; amount <= 20; ++amount)
	{
		auto changeCoins = coinChangeWithTracking(coins, amount);

		if (changeCoins.empty())
			cout << "  <FAILED> Amount [" << amount << "] cents cannot be constructed with given coins." << endl;
		else
		{
			string coinSequence = "{ ";
			for (auto coin : changeCoins)
				coinSequence += toString(coin) + " ";
			coinSequence += "}";

			cout << "Need " << coinSequence.c_str() << " coins to construct amount [" << amount << "] cents." << endl;
		}
	}
}
