#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto & p : v)
    cin >> p.first >> p.second;

  sort(v.begin(), v.end(), [&](auto & a, auto & b) {
    return (double)a.first/a.second < (double)b.first/b.second;
  });

  for (auto & p : v) {
    cout << p.first << ' ' << p.second << "\n";
  }

}
