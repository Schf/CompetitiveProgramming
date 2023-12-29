#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
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

#define POW2(N1) ((N1) * (N1))
#define DIST(P1, P2) (sqrt(POW2(P1.f - P2.f) + POW2(P1.s - P2.s)))

vector<double> dp;
vector<vector<double>> dd;

double calc(ll state) {
  if (dp[state] >= 0)
    return dp[state];

  dp[state] = (double)INFLL;

  for (ll i = 0; i < dd.size() - 1; ++i) {
    for (ll j = i + 1; j < dd.size(); ++j) {
      if (((state >> i) & 1) && ((state >> j) & 1)) {
        ll cstate = state & ~((1 << i) | (1 << j));
        dp[state] = min(dp[state], calc(cstate) + dd[i][j]);
      }
    }
  }

  // for(ll i = 0; i < dd.size(); ++i)
  //   cout << ((state>>i)&1);
  // cout << ' ' << dp[state] << endl;

  return dp[state];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n;

  cin >> n;
  for (int CASE = 1; n; ++CASE) {
    string s;
    vector<pll> cc(2 * n);

    for (i = 0; i < cc.size(); ++i)
      cin >> s >> cc[i].f >> cc[i].s;

    dd = vector<vector<double>>(2 * n, vector<double>(2 * n));
    for (i = 0; i < cc.size(); ++i)
      for (j = 0; j < cc.size(); ++j)
        if (i == j)
          dd[i][j] = INF;
        else
          dd[i][j] = DIST(cc[i], cc[j]);

    dp = vector<double>(1 << (2 * n), -1);
    dp[0] = 0;
    // for (i = 0; i < dd.size(); ++i) {
    //   for (j = i + 1; j < dd.size(); ++j) {
    //     dp[(1 << i) | (1 << j)] = dd[i][j];
    //   }
    // }

    cout << "Case " << CASE << ": " << fixed << setprecision(2)
         << calc((1 << (2 * n)) - 1) << endl;

    cin >> n;
  }

  return 0;
}
