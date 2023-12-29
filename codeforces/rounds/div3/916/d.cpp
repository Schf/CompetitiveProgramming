#include <bits/stdc++.h>
#include <cstring>
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
  ll i, j, n, d = 3, T;
  cin >> T;
  while (T--) {
    cin >> n;
    ll v[n][d], dp[n + 1][1 << d];
    memset(dp, 0, sizeof(dp));
    for (j = 0; j < d; ++j)
      for (i = 0; i < n; ++i)
        cin >> v[i][j];
    for (i = 1; i <= n; ++i) {
      for (j = 0; j < (1 << d); ++j) {
        dp[i][j] = dp[i - 1][j];
        for (ll l = 0; l < d; ++l)
          if (j & (1 << l))
            dp[i][j] = max(dp[i][j], dp[i - 1][j - (1 << l)] + v[i - 1][l]);
      }
    }
    cout << dp[n][(1 << d) - 1] << '\n';
  }

  return 0;
}
