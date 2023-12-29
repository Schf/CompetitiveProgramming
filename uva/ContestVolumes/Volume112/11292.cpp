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
  ll i, j, n, m;

  while (scanf("%lld %lld", &n, &m), n != 0 && m != 0) {
    vll N(n), M(m);
    trav(e, N) scanf("%lld", &e);
    trav(e, M) scanf("%lld", &e);
    if (m < n) {
      printf("Loowater is doomed!\n");
      continue;
    }
    sort(N.begin(), N.end());
    sort(M.begin(), M.end());
    ll res = 0;
    for (i = j = 0; i < n && j < m; ++i, ++j) {
      while (j < m && M[j] < N[i])
        ++j;
      if (j < m)
        res += M[j];
    }
    if (i < n)
      printf("Loowater is doomed!\n");
    else
      printf("%lld\n", res);
  }

  return 0;
}
