#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n));
  for (auto &v : m)
    for (auto &e : v)
      cin >> e;

  {
    auto c(m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        c[i][j] = m[j][n - i - 1];
    for (auto &v : c) {
      for (auto &e : v)
        cout << e << ' ';
      cout << '\n';
    }
    cout << '\n';
  }

  {
    auto c(m);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        c[i][j] = m[j][i];
    for (auto &v : c) {
      for (auto &e : v)
        cout << e << ' ';
      cout << '\n';
    }
    cout << '\n';
  }

  {
    {
      auto c(m);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          c[i][j] = m[i][n - j - 1];
      for (auto &v : c) {
        for (auto &e : v)
          cout << e << ' ';
        cout << '\n';
      }
      cout << '\n';
    }
    {
      auto c(m);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          c[i][j] = m[n - i - 1][j];
      for (auto &v : c) {
        for (auto &e : v)
          cout << e << ' ';
        cout << '\n';
      }
    }
    cout << '\n';
  }

  return 0;
}
