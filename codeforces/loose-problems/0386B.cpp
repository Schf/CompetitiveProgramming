#include <bits/stdc++.h>
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
  ll i, j, n, t;

  cin >> n;
  vll v(n);
  trav(e, v) cin >> e;
  sort(v.begin(), v.end());
  cin >> t;

  ll r = 0;
  for (i = j = 0; i < n; ++i) {
    for (; j < n && v[j] - v[i] <= t; ++j)
      ;
    r = max(r, j - i);
  }

  cout << r << '\n';

  return 0;
}
