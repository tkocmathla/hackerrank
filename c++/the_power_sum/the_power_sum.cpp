#include <cmath>
#include <iostream>

using namespace std;

int find_pow_sum(double n, double p, double i) {
  if (n == 0) return 1;
  if (pow(i, p) > n) return 0;

  return find_pow_sum(n-pow(i, p), p, i+1)
       + find_pow_sum(n, p, i+1);
}

int main() {
  double n, p; // X = n, N = p
  cin >> n >> p;

  cout << find_pow_sum(n, p, 1) << endl;
  return 0;
}
