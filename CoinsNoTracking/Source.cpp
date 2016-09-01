#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

size_t coinChange(vector<size_t>& coins, size_t amount)
{
	const size_t infinity = (size_t)-1;
	if (amount == 0)
		return 0;

	sort(coins.begin(), coins.end());

	vector<size_t> min_arr(amount + 1, infinity);
	min_arr[0] = 0;

	for (size_t i = 1; i <= amount; ++i)
	{
		for (size_t c = 0; c < coins.size(); ++c)
		{
			if (coins[c] > i)
				break;

			if (min_arr[i - coins[c]] != infinity)
				min_arr[i] = min(min_arr[i], min_arr[i - coins[c]] + 1);
		}
	}

	return (min_arr[amount] == 0 || min_arr[amount] == infinity)
		? -1
		: min_arr[amount];
}

int main()
{
	vector<size_t> coins = { 3, 5 };
	cout << "Available coins: { ";
	copy(coins.begin(), coins.end(), ostream_iterator<size_t>(cout, " "));
	cout << "}\n" << endl;

	for (size_t amount = 0; amount <= 20; ++amount)
	{
		size_t numCoins = coinChange(coins, amount);

		if (numCoins == (size_t)-1)
			cout << "  <FAILED> Amount [" << amount << "] cents cannot be constructed with given coins." << endl;
		else
			cout << "Need " << numCoins << " coins to construct amount [" << amount << "] cents." << endl;
	}
}
