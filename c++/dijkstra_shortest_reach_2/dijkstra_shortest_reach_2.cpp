#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct edge {
  int label;
  int weight;
};

typedef vector<vector<edge>> graph;
typedef pair<int, int> ipair;

vector<long long> dijkstra(const graph &g, int start) {
  priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
  vector<long long> dist(g.size(), numeric_limits<long long>::max());

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto i : g[u]) {
      int v = i.label;
      int w = i.weight;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

int main() {
  int t;
  cin >> t;

  for (auto i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> costs(n+1, vector<long long>(n+1, numeric_limits<long long>::max()));
    graph g(n+1);
    for (auto j = 0; j < m; ++j) {
      int x, y, w;
      cin >> x >> y >> w;
      if (costs[x][y] > w) {
        g[x].push_back({y, w});
        costs[x][y] = w;
      }
      if (costs[y][x] > w) {
        g[y].push_back({x, w});
        costs[y][x] = w;
      }
    }

    int s;
    cin >> s;

    vector<long long> dist = dijkstra(g, s);
    for (auto j = 1; j < dist.size(); ++j)
      if (j != s)
        if (dist[j] == numeric_limits<long long>::max())
          cout << -1 << " ";
        else
          cout << dist[j] << " ";
    cout << endl;
  }

  return 0;
}
