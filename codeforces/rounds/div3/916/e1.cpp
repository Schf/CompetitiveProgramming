#include <algorithm>
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

ll solve(ll state, vll &a, vll &b, vll &dp) {
  if (!state)
    return 0;
  if (dp[state] > -INFLL)
    return dp[state];
  ll r = -INFLL;
  for (ll i = 0; i < a.size(); ++i)
    if (state & (1 << i))
      r = max(r, a[i] - solve(state - (1 << i), b, a, dp) - 1);
  return dp[state] = r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    vll a(n), b(n), dp(1 << n, -INFLL);
    trav(e, a) cin >> e;
    trav(e, b) cin >> e;
    cout << solve((1 << n) - 1, a, b, dp) << '\n';
  }

  return 0;
}
