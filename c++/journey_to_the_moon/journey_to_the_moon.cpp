#include <stack>
#include <vector>
#include <iostream>

using namespace std;

vector<int> dft(const vector<vector<int>> &g, vector<bool> &visited, int start) {
  vector<int> nodes;
  stack<int> s;
  s.push(start);
  
  while (s.size() > 0) {
    auto v = s.top();
    s.pop();
    if (!visited[v]) {
      for (auto i = 0; i < g[v].size(); ++i)
        s.push(g[v][i]);
      visited[v] = true;
      nodes.push_back(v);
    }
  }
  return nodes;
}
 
int main() { 
  auto n = 0, p = 0;
  cin >> n >> p;
  vector<vector<int>> g(n);
  for (auto i = 0; i < p; ++i) {
    auto a = 0, b = 0;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
 
  long long sum_of_sizes = 0;
  long long result = 0;
  vector<vector<int>> subgraphs;
  vector<bool> visited(g.size());
  for (auto i = 0; i < g.size(); ++i) {
    vector<int> nodes = dft(g, visited, i);
    if (nodes.size() > 0) {
      result += sum_of_sizes * nodes.size();
      sum_of_sizes += nodes.size();
      subgraphs.push_back(nodes);
    }
  }
    
  cout << result << endl;
  return 0;
}
