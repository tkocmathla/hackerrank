#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct edge {
  int label;
  int weight;
};

typedef vector<vector<edge>> graph;
typedef pair<int, int> ipair;

long long dijkstra(const graph &g, int start, int end) {
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
      long long d;
      if (w - dist[u] < 0)
        d = dist[u];
      else
        d = dist[u] + (w - dist[u]);

      if (dist[v] > d) {
        dist[v] = d;
        pq.push({dist[v], v});
      }
    }
  }

  return dist[end];
}

int main() {
  int n, e;
  cin >> n >> e;

  graph g(n+1);
  for (auto i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  long long cost = dijkstra(g, 1, n);
  if (cost == numeric_limits<long long>::max())
    cout << "NO PATH EXISTS" << endl;
  else
    cout << cost << endl;

  return 0;
}
