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
  ll i, j, n, k, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vll a(n), h(n), raw(n + 1), app(n + 1);
    trav(e, a) cin >> e;
    trav(e, h) cin >> e;
    app[n - 1] = a[n - 1];
    for (i = n - 2; i >= 0; i--)
      raw[i] = (raw[i + 1] + 1) * (!(h[i] % h[i + 1])),
      app[i] = (app[i + 1] * (!(h[i] % h[i + 1]))) + a[i];
    ll l = 0, r = 1, res = (a[0] <= k);
    for (; r < n; r++) {
      if (raw[r - 1] == 0)
        l = r;
      while (l < r && app[l] - app[r + 1] * (raw[r] != 0) > k)
        l++;
      if (app[l] - app[r + 1] * (raw[r] != 0) <= k)
        res = max(res, r - l + 1);
    }
    cout << res << endl;
  }

  return 0;
}
