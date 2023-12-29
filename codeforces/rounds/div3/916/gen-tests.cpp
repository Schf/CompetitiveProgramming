#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

const ll MOD = 1e+9 + 7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n;
  vector<vll> tests;
  for (j = 0, n = 1; n <= 6; ++n) {
    vll test(2 * n);
    for (i = 0; i < n; ++i)
      test[2 * i] = test[2 * i + 1] = i + 1;
    do {
      tests.emplace_back(2 * n);
      for (i = 0; i < 2 * n; ++i)
        tests[tests.size() - 1][i] = test[i];
    } while (next_permutation(test.begin(), test.end()));
  }
  cout << tests.size() << '\n';
  trav(v, tests) {
    cout << v.size() / 2 << '\n';
    trav(e, v) cout << e << ' ';
    cout << '\n';
  }

  return 0;
}
