#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;

vector<long long> bfs(const graph &g, int start) {
  vector<long long> dist(g.size(), -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto v : g[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 6;
        q.push(v);
      }
    }
  }

  return dist;
}

int main() {
  int q;
  cin >> q;

  for (auto i = 0; i < q; ++i) {
    int n, m;
    cin >> n >> m;

    graph g(n);
    vector<vector<bool>> edges(n, vector<bool>(n, false));
    for (auto j = 0; j < m; ++j) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      if (!edges[u][v]) {
        g[u].push_back(v);
        edges[u][v] = true;
      }
      if (!edges[v][u]) {
        g[v].push_back(u);
        edges[v][u] = true;
      }
    }

    int s;
    cin >> s;
    s--;

    vector<long long> dist = bfs(g, s);
    for (auto j = 0; j < dist.size(); ++j)
      if (j != s)
        cout << dist[j] << " ";
    cout << endl;
  }
}
