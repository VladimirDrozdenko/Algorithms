#include <iostream>
using namespace std;


int main() {
  int a[] = {5, -6, 3, 4, -2, 3, -1, 2, -3};
  size_t n = sizeof(a) / sizeof(*a);

  int ps[1000];
  ps[0] = a[0];
  for (size_t i = 1; i < n; ++i) {
    ps[i] = ps[i-1] + a[i];
  }

  int max_sum = ps[0];
  size_t min_val_idx = 0;

  for (size_t r = 1; r < n; ++r) {
    max_sum = max(max_sum, ps[r] - ps[min_val_idx]);

    if (ps[min_val_idx] > ps[r]) {
      min_val_idx = r;
    }
  }

  cout << "Max sum: " << max_sum << endl;
}
