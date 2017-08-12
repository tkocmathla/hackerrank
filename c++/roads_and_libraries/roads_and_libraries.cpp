#include <bits/stdc++.h>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

int dft(const vector<vector<int>> &g, vector<bool> &visited, int start) {
  stack<int> s;
  s.push(start);
  int count = 0;
  
  while (s.size() > 0) {
    int v = s.top();
    s.pop();    
    if (!visited[v]) {
      for (int i = 0; i < g[v].size(); ++i)
        s.push(g[v][i]);
      visited[v] = true;
      count += 1;
    }
  }
  return count;
}

int main() {
  int q;
  cin >> q;
  
  for (int i = 0; i < q; ++i) {
    int v;       // # cities
    int e;       // # roads
    long lcost;  // library cost
    long rcost;  // road cost
    cin >> v >> e >> lcost >> rcost;
    
    // Build adjacency list
    vector<vector<int>> g;
    for (int j = 0; j < v; ++j)
      g.push_back(vector<int>());
    for (int j = 0; j < e; ++j) {
      int v1, v2;
      cin >> v1 >> v2;
      g[v1-1].push_back(v2-1);
      g[v2-1].push_back(v1-1);
    }
    
    // Calculate cost
    long cost = 0;
    if (lcost < rcost) {
      cost = lcost * v;
    }
    else {
      vector<bool> visited;
      for (int i = 0; i < v; ++i) 
        visited.push_back(false);
      for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
          int count = dft(g, visited, i);
          cost += lcost + (rcost * (count - 1));
        }
      }
    }
    cout << cost << endl;
  }
  return 0;
}
