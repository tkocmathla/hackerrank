#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool bigsort(string a, string b) {
  if (a.size() < b.size())
    return true;
  else if (a.size() > b.size())
    return false;

  for (auto i = 0; i < a.size(); ++i) {
    if (a[i] < b[i])
      return true;
    else if (a[i] > b[i])
      return false;
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  vector<string> nums(n);
  for (auto i = 0; i < n; ++i)
    cin >> nums[i];

  sort(nums.begin(), nums.end(), bigsort);
  for (auto x : nums)
    cout << x << endl;

  return 0;
}
