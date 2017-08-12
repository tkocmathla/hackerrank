#include <iostream>
#include <limits>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void merge(unordered_map<long, vector<pair<long, long>>> &pairs, long r) {
  stack<pair<long, long>> s;
  s.push(pairs[r][0]);

  for (long i = 1; i < pairs[r].size(); ++i) {
    pair<long, long> top = s.top();

    if (top.second < pairs[r][i].first)
      s.push(pairs[r][i]);
    else if (top.second < pairs[r][i].second) {
      top.second = pairs[r][i].second;
      s.pop();
      s.push(top);
    }
  }

  pairs[r].clear();
  while (!s.empty()) {
    pairs[r].push_back(s.top());
    s.pop();
  }
}

int main() {
  long n, m, k;
  cin >> n >> m >> k;

  unordered_map<long, vector<pair<long, long>>> tracks;
  for (long i = 0; i < k; ++i) {
    long r, c1, c2;
    cin >> r >> c1 >> c2;

    if (tracks.find(r) == tracks.end()) {
      tracks.insert({r, {{c1, c2}}});
    }
    else {
      tracks[r].push_back({c1, c2});
      merge(tracks, r);
    }
  }

  auto count = n * m;
  for (auto x : tracks)
    for (auto y : x.second)
      count -= y.second - y.first + 1;

  cout << count;
  return 0;
}
