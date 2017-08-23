#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (auto i = 0; i < t; ++i) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto j = 0; j < n; ++j)
      cin >> a[j];

    vector<int> lsums(n);
    vector<int> rsums(n);
    lsums[0] = 0;
    rsums[n-1] = 0;
    for (auto j = 1; j < n; ++j) {
      lsums[j] = lsums[j-1] + a[j-1];
      rsums[n-1-j] = rsums[n-j] + a[n-j];
    }

    bool found = false;
    for (auto i = 0; i < n; ++i) {
      if (lsums[i] == rsums[i]) {
        found = true;
        break;
      }
    }

    if (found)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  }

  return 0;
}
