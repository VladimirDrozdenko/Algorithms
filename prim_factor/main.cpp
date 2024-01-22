#include <iostream>

using namespace std;

class Factorization {
  const static size_t max_len = 100;

  size_t fact;
  size_t len;

  size_t p[max_len];
  size_t e[max_len];

public:
  Factorization() : fact(0), len(0) {
  }

  void prime_factorization(size_t n) {
    fact = n;
    len = 0;

    if (n <= 3) {
      p[0] = n;
      e[0] = 1;
      len = 1;
      return;
    }

    size_t d = 2;
    while (n > 1 && d*d <= n) {
      size_t e_cnt = 0;
      while (n % d == 0) {
        n /= d;
        ++e_cnt;
      }

      if (e_cnt > 0) {
        p[len] = d;
        e[len] = e_cnt;
        ++len;
      }

      ++d;
    }

    if (n > 1) {
      p[len] = n;
      e[len] = 1;
      ++len;
    }
  }

  void print_factorization() {
    
    cout << fact << " = ";

    for (size_t i = 0; i < len; ++i) {
      cout << p[i] << "^" << e[i];
      if (i + 1 < len) {
        cout << " * ";
      } else {
        cout << endl;
      }
    }
  }

};

int main() {

  Factorization fact;

  fact.prime_factorization(1982738493);
  fact.print_factorization();

  for (size_t i = 0; i <= 500; ++i) {
    fact.prime_factorization(i);
    fact.print_factorization();
  }
  
  return 0;
}