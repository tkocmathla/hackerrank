#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef vector<vector<char>> grid;

struct position {
  int row;
  int col;
  int length;
  bool orientation; // 0 = vertical, 1 = horizontal
};

vector<position> find_starts(const grid& g) {
  vector<position> starts;
  for (auto i = 0; i < g.size(); ++i) {
    for (auto j = 0; j < g[i].size(); ++j) {
      if (g[i][j] == '+') continue;

      int length = 0;
      if (i != g.size()-1 && ((i == 0 && g[i+1][j] == '-') || (i > 0 && g[i-1][j] == '+' && g[i+1][j] == '-'))) {
        for (int ii = i; ii < g.size() && g[ii][j] == '-'; ++ii)
          length++;
        starts.push_back({i, j, length, 0});
      }
      else if (j != g[i].size()-1 && ((j == 0 && g[i][j+1] == '-') || (j > 0 && g[i][j-1] == '+' && g[i][j+1] == '-'))) { 
        for (int jj = j; jj < g[i].size() && g[i][jj] == '-'; ++jj)
          length++;
        starts.push_back({i, j, length, 1});
      }
    }
  }
  return starts;
}

vector<position> find_placements(const grid& g, const string& word, const vector<position>& starts) {
  vector<position> places;

  for (auto start : starts) {
    if (start.length != word.size()) continue;

    bool ok = true;
    if (start.orientation == 0) { // vertical
      for (auto i = start.row; i < start.row + start.length; ++i) {
        if (g[i][start.col] != '-' && g[i][start.col] != word[i - start.row]) {
          ok = false;
          break;
        }
      }
    }
    else { // horizontal
      for (auto j = start.col; j < start.col + start.length; ++j) {
        if (g[start.row][j] != '-' && g[start.row][j] != word[j - start.col]) {
          ok = false;
          break;
        }
      }
    }
    if (ok) places.push_back(start);
  }

  return places;
}

void place_word(grid& g, const string& word, const position& pos) {
  if (pos.orientation == 0) // vertical
    for (auto i = pos.row; i < pos.row + pos.length; ++i)
      g[i][pos.col] = word[i - pos.row];
  else // horizontal
    for (auto j = pos.col; j < pos.col + pos.length; ++j)
      g[pos.row][j] = word[j - pos.col];
}

grid solve(grid g, unordered_set<string> words, vector<position> starts) {
  if (words.empty()) return g;

  for (auto word : words) {
    vector<position> places = find_placements(g, word, starts);
    if (places.size() == 0) return {};

    for (auto p : places) {
      grid g2 = g;
      place_word(g2, word, p);
      unordered_set<string> new_words = words;
      new_words.erase(word);
      grid solution = solve(g2, new_words, starts);
      if (solution.size() > 0)
        return solution;
    }
  }

  return {};
}

int main() {
  string line;
  grid g;
  for (auto i = 0; i < 10; ++i) {
    cin >> line;
    g.push_back(vector<char>());
    for (auto j = 0; j < 10; ++j)
      g[i].push_back(line[j]);
  }

  cin >> line;
  stringstream ss(line);
  string word;
  unordered_set<string> words;
  while (getline(ss, word, ';'))
    words.insert(word);
  
  vector<position> starts = find_starts(g);
  grid solved = solve(g, words, starts);
  
  for (auto row : solved) {
    for (auto col : row) {
      cout << col;
    }
    cout << endl;
  }
  return 0;
}
