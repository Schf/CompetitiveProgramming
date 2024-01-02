#include <bits/stdc++.h>
using namespace std;

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
    for (auto &e : a)
      cin >> e;
    long double r = 1;
    cout << 1;
    for (i = j = 1; i < n; ++i) {
      r *= (long double)a[i] / a[i - 1];
      for (; j <= i && (long double)a[i - j] / (j+1) >= 1; ++j)
        ;
      cout << ' ' << j;
    }
    cout << '\n';
  }

  return 0;
}
