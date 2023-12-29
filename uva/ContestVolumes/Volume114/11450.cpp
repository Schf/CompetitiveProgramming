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

vector<vector<short>> dp;
vector<vll> C;

short calc(ll price, ll state) {
  if (dp[price][state] >= 0)
    return dp[price][state];

  for (ll i = 0; i < C.size(); ++i) {
    if ((state >> i) & 1) {
      for (ll j = 0; j < C[i].size(); ++j) {
        if (price - C[i][j] < 0)
          continue;
        dp[price][state] =
            max<ll>(dp[price][state],
                    calc(price - C[i][j], state ^ (1 << i)) + C[i][j]);
      }
    }
  }

  if (dp[price][state] < 0)
    dp[price][state] = 0;

  return dp[price][state];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, TT;
  scanf("%lld", &TT);
  while (TT--) {
    ll m, c, k;
    scanf("%lld %lld", &m, &c);
    dp = vector<vector<short>>(m+1, vector<short>(1 << c, -1));
    for (i = 0; i < dp.size(); ++i)
      dp[i][0] = 0;
    for (i = 0; i < dp[0].size(); ++i)
      dp[0][i] = 0;
    C = vector<vll>(c);
    trav(v, C) {
      scanf("%lld", &k);
      v = vll(k);
      trav(e, v) scanf("%lld", &e);
      sort(v.begin(), v.end());
    }
    short r = calc(m, (1 << c) - 1);
    if (r > 200)
      printf("no solution\n");
    else
      printf("%d\n", r);
  }

  return 0;
}
