#include <cmath>
#include <iostream>

using namespace std;

class Solution {

    inline static bool isPrime(int n) {
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;

        const int sqrtN = sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;

        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                ++cnt;
            }
        }

        return cnt;
    }
};


int main() {
  Solution sln;
  cout << sln.countPrimes(100000000) << endl;
}