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
  ll i, j, n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    vll a(n);
    ll d = 0;
    trav(e, a) cin >> e;
    trav(e, a) cin >> j, d -= j - 1, e += j - 2;
    sort(a.begin(), a.end());
    for (i = 0; i < n; ++i)
      d += (1 - (1 & i)) * a[n - i - 1];
    cout << d << '\n';
  }

  return 0;
}
