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

int OK(vll &v, ll t, ll x) {
  ll r = 0;
  trav(a, v) r += max(0LL, t - a);
  return r <= x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, x, t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    vll v(n);
    trav(a, v) cin >> a;
    ll p = 0, j = MOD;
    for (; j; j >>= 1)
      while (OK(v, p + j, x))
        p += j;
    cout << p << endl;
  }

  return 0;
}
