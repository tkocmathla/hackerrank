#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

string super_digit(string s, long long k) {
  if (s.size() == 1 && k == 1)
    return s;

  long long sum = 0;
  for (auto c : s)
    sum += strtoull(&c, nullptr, 10);

  stringstream ss;
  ss << sum * k;
  return super_digit(ss.str(), 1);
}

int main() {
  string n;
  long long k;
  cin >> n >> k;

  cout << super_digit(n, k);
  return 0;
}
