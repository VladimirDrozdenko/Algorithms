#include <iostream>
#include <set>
using namespace std;


int main() {
  int a[] = {6, 3, 7, 1, 4, 2, 5, 0, 3, 8, 10, 0};
  const size_t n = sizeof(a) / sizeof(*a);

  size_t res_left = 0, res_right = 0;

  for (size_t left = 0; left < n; ++left) {
    set<int> s;
    int max_val = a[left], min_val = a[left];

    size_t right = left;
    for (; right < n; ++right) {
      if (!s.insert(a[right]).second) {
        // this element is not unique
        break;
      }
      max_val = max(max_val, a[right]);
      min_val = min(min_val, a[right]);

      if (max_val - min_val + 1 == right - left + 1) {
        if (res_right - res_left < right - left + 1) {
          res_right = right;
          res_left = left;
        }
      } 
    }
  }

  cout << "Res seq: ";
  for (size_t i = res_left; i <= res_right; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
}