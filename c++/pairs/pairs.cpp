#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  unordered_set<int> s;
  for (auto i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    s.insert(tmp);
  }

  auto ans = 0;
  for (auto x : s) {
    if (s.find(x - k) != s.end()) {
      ans += 1;
    }
  }

  cout << ans;
  return 0;
}
