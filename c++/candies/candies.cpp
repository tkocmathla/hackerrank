#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<long long> a(n); // scores
  vector<long long> c(n); // candies

  for (auto i = 0; i < n; ++i) {
    cin >> a[i];
    c[i] = 1;
  }

  // forward sweep (ascending sequences)
  for (auto i = 1; i < n; ++i)
    if (a[i] > a[i-1])
      c[i] = c[i-1] + 1;

  // backward sweep (descending sequences)
  for (auto i = n-2; i >= 0; --i)
    if (a[i] > a[i+1])
      c[i] = max(c[i], c[i+1] + 1);

  long long sum = 0;
  for (auto x : c)
    sum += x;
  cout << sum << endl;

  return 0;
}
