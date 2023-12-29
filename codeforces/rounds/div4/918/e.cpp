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
    vll a(n + 2);
    for (i = 2; i < n + 2; ++i)
      cin >> a[i], a[i] += a[i - 2];
    for (i = 0; i < a.size(); ++i)
      cout << a[i] << ' ';
    cout << '\n';
    for (i = 2; i < n + 2; ++i)
      for (j = i + 1; j < n + 2; ++j)
        if (a[j & ~1] - a[i + (i & 1) - 2] == a[j - !(j & 1)] - a[(i | 1) - 2])
          cout << "YES: <" << i << ' ' << (i + (i & 1)) << ' ' << (i | 1)
               << "> <" << j << ' ' << (j & ~1) << ' ' << (j - !(j & 1)) << "> "
               << a[j & ~1] - a[i + (i & 1) - 2] << ' '
               << a[j - !(j & 1)] - a[(i | 1) - 2] << "\n",
              i = n + 10, j = n + 10;
    if (i <= n + 7)
      cout << "NO\n";
  }

  return 0;
}
