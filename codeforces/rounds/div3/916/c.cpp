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
  ll i, j, n, k, T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vll a(n), b(n);
    trav(e, a) cin >> e;
    trav(e, b) cin >> e;
    for (i = 1; i < n; ++i)
      a[i] += a[i - 1], b[i] = max(b[i], b[i - 1]);
    ll r = 0;
    for (i = 0; i < n; ++i)
      if (k - i - 1 >= 0)
        r = max(r, a[i] + b[i] * (k - i - 1));
    cout << r << '\n';
  }

  return 0;
}
