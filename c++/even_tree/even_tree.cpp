#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int dft(const vector<vector<int>> &g, int start) {
  vector<bool> visited(g.size());
  stack<int> s;
  s.push(start);
  
  int count = 0;
  while (s.size() > 0) {
    auto v = s.top();
    s.pop();
    if (!visited[v]) {
      for (auto i = 0; i < g[v].size(); ++i)
        s.push(g[v][i]);
      visited[v] = true;
      count += 1;
    }
  }
  return count;
}
 
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n+1);
  for (auto i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }

  int count = 0;

  for (auto u = 1; u < g.size(); ++u) {
    for (auto i = g[u].size(); i-- > 0; ) {
      if (dft(g, g[u][i]) % 2 == 0) {
        g[u].erase(g[u].begin()+i);
        count += 1;
      }
    }
  }

  cout << count << endl;
  return 0;
}
