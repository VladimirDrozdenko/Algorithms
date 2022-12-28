#include <iostream>

//
// Returns number of elements of the longest Arithmetic Progression
// in the 'a' sequence.
//
// Time: O(n^3)
// Space: O(1)
//
int getLongestAPCountOn3(const int *a, int n) {
    int max_len = 0;

    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int d = a[j] - a[i];
            int len = 2;
            int last_checked = a[j];
            for (int k = j+1; k < n; ++k) {
                if (last_checked + d == a[k]) {
                    ++len;
                    last_checked = a[k];
                }
            }
            max_len = std::max(max_len, len);
        }
    }
    return max_len;
}

//
// Returns number of elements of the longest Arithmetic Progression
// in the 'a' sequence.
//
// Time: O(n^2)
// Space: O(n^2)
//
int getLongestAPCountOn2(const int *a, int n) {

    int L[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            L[i][j] = 2;
        }
    }

    int max_count = 2;

    for (int j = n-2; j > 0; --j) {
        int i = j - 1;
        int k = j + 1;
        while (i >= 0 && k < n) {
            if (a[i] + a[k] < 2 * a[j]) {
                ++k;
            } else if (a[i] + a[k] > 2 * a[j]) {
                --i;
            } else {
                L[i][j] = L[j][k] + 1;

                max_count = std::max(max_count, L[i][j]);

                --i;
                ++k;
            }
        }
    }

    return max_count;
}

int main() {
    const int a[] = {1, 7, 10, 15, 27, 29}; // Expected 3 as [7, 15, 27]
    //const int a[] = {5, 10, 15, 20, 25, 28, 30}; // expected 6 as [5, 10, 15, 20, 25, 30]
    const int n = sizeof(a)/sizeof(*a);

    int max_len = getLongestAPCountOn2(a, n);

    std::cout << max_len << std::endl;
}


