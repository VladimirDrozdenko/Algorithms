#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	size_t amount = 11;
	vector<size_t> coins = {1, 3, 5};
	sort(coins.begin(), coins.end());

	vector<size_t> min_arr(amount+1, numeric_limits<size_t>::max());
	min_arr[0] = 0;

	for (size_t i = 1; i <= amount; ++i)
	{
		for (size_t c = 0; c < coins.size(); ++c)
		{
			if (coins[c] > i)
				break;
			
			min_arr[i] = min(min_arr[i], min_arr[i - coins[c]] + 1);
		}
	}

	cout << min_arr[amount] << endl;
}
