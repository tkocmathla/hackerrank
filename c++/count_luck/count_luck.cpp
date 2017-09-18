#include <iostream>
#include <vector>

using namespace std;

vector<int> neighbors(const vector<vector<char>> &forest, const vector<bool> &visited, int i, int j) {
  vector<int> neighbors;
  auto n = forest.size();
  auto m = forest[0].size();

  if (i > 0 && forest[i-1][j] != 'X') {
    auto x = (i-1)*m+j;
    if (!visited[x]) neighbors.push_back(x);
  }
  if (j < m-1 && forest[i][j+1] != 'X') {
    auto x = i*m+j+1;
    if (!visited[x]) neighbors.push_back(x);
  }
  if (i < n-1 && forest[i+1][j] != 'X') {
    auto x = (i+1)*m+j;
    if (!visited[x]) neighbors.push_back(x);
  }
  if (j > 0 && forest[i][j-1] != 'X') {
    auto x = i*m+j-1;
    if (!visited[x]) neighbors.push_back(x);
  }

  return neighbors;
}

int dfs(const vector<vector<char>> &forest, vector<bool> visited, int node, int count) {
  auto n = forest.size();
  auto m = forest[0].size();
  auto i = node / m;
  auto j = node % m;
  if (visited[node]) return 0;
  if (forest[i][j] == '*') return count;

  visited[node] = true;
  auto ns = neighbors(forest, visited, i, j);
  for (auto n : ns) {
    auto new_count = dfs(forest, visited, n, ns.size() > 1 ? count+1 : count);
    if (new_count > 0) return new_count;
  }

  return 0;
}

int main() {
  int t;
  cin >> t;

  for (auto i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> forest;
    int start;
    for (auto j = 0; j < n; ++j) {
      forest.push_back({});
      for (auto k = 0; k < m; ++k) {
        char c;
        cin >> c;
        forest[j].push_back(c);
        if (c == 'M') start = j*m+k;
      }
    }

    int k;
    cin >> k;

    vector<bool> visited(n*m, false);
    auto count = dfs(forest, visited, start, 0);
    if (count == k) 
      cout << "Impressed" << endl;
    else
      cout << "Oops!" << endl;
  }

  return 0;
}
