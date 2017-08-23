#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int binary_search(const vector<pair<int, int>>& costs, int first, int last, int value) {
  if (first > last)
    return -1;

  int mid = (first + last) / 2;
  if (costs[mid].first == value)
    return costs[mid].second;
  else if (value < costs[mid].first)
    return binary_search(costs, first, mid-1, value);
  else
    return binary_search(costs, mid+1, last, value);
}

int main() {
  int t;
  cin >> t;

  for (auto i = 0; i < t; ++i) {
    int m, n;
    cin >> m >> n; // m = money, n = # flavors

    vector<pair<int, int>> costs;
    for (auto j = 0; j < n; ++j) {
      int c;
      cin >> c;
      costs.push_back({c, j});
    }
    sort(costs.begin(), costs.end());

    for (auto j = 0; j < n-1; ++j) {
      int cost = m - costs[j].first;
      if (cost >= costs[j].first) {
        int index = binary_search(costs, j+1, n-1, cost);
        if (index > -1) {
          cout << min(costs[j].second, index)+1 << " " 
               << max(costs[j].second, index)+1 << endl;
          break;
        }
      }
    }
  }

  return 0;
}
