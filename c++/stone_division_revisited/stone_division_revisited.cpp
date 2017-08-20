#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long divide(long long n, const vector<long long>& s, unordered_map<long long, long long>& dp) {
  if (dp.find(n) != dp.end()) return dp[n];

  long long ans = 0;
  for (auto x : s)
    if (x != n && n % x == 0)
      ans = max(ans, 1 + ((n/x) * divide(x, s, dp)));

  dp[n] = ans;
  return ans;
}

int main() {
  int q;
  cin >> q;

  for (auto i = 0; i < q; ++i) {
    long long n, m;
    cin >> n >> m; // n = initial pile size, m = query set size

    unordered_map<long long, long long> dp;
    vector<long long> s(m);
    for (auto j = 0; j < m; ++j)
      cin >> s[j];
    
    cout << divide(n, s, dp) << endl;  
  }

  return 0;
}
