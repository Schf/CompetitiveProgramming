#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mt19937_64 rng(4307106760804231263);
  ll i, j, n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    vll a(2 * n), r(n, -1), g(2 * n, -1), c, f(2 * n, 1);
    map<ll, ll> x;
    trav(e, a) cin >> e, --e;
    trav(e, r) while (e < 1) e = rng() >> 1;
    for (i = j = 0; i < 2 * n; ++i) {
      x[j] = i;
      j ^= r[a[i]];
      g[i] = i + 1;
      if (j == 0) {
        c.push_back(0);
        for (ll l = x[0]; l <= i; l = g[l])
          c[c.size() - 1] += f[l];
        x.clear();
      } else if (x.count(j)) {
        g[x[j] - 1] = i;
        f[i] = 0;
      }
    }
    // trav(e, a) cout << setw(2) << e << ' ';
    // cout << '\n';
    // for (i = 0; i < 2 * n; ++i)
    //   cout << setw(2) << i << ' ';
    // cout << '\n';
    // trav(e, g) cout << setw(2) << e << ' ';
    // cout << '\n';
    ll m = 1;
    trav(e, c) m = (m * e) % MOD;
    // cout << n << " | ";
    // for (i = 0; i < 2 * n; ++i)
    //   cout << a[i] + 1 << ' ';
    // cout << "| ";
    cout << c.size() << ' ' << m << '\n';
  }

  return 0;
}
