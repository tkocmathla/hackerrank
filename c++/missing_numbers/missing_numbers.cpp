#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  unordered_map<int, int> a;
  unordered_map<int, int> b;

  int n; cin >> n;
  for (auto i = 0; i < n; ++i) {
    int tmp; cin >> tmp;
    a[tmp]++;
  }

  int m; cin >> m;
  for (auto i = 0; i < m; ++i) {
    int tmp; cin >> tmp;
    b[tmp]++;
  }

  set<int> missing;
  for (auto it = b.begin(); it != b.end(); ++it) {
    if (a.find(it->first) == a.end()) {
      for (auto i = 0; i < it->second; ++i)
        missing.insert(it->first);
    }
    else if (a[it->first] < it->second) {
      for (auto i = 0; i < it->second - a[it->first]; ++i)
        missing.insert(it->first);
    }
  }

  for (auto m : missing)
    cout << m << " ";
  cout << endl;

  return 0;
}
