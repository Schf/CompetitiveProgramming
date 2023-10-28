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
  ll i, j, n;

  while (cin >> n) {
    if (!n)
      break;
    vll c(n), p(n), s(n, -1);
    for (int i = 0; i < n; ++i)
      cin >> c[i] >> p[i];
    for (i = 0; i < n; ++i)
      if (i + p[i] > n || i + p[i] < 0)
        break;
      else if (s[i + p[i]] >= 0)
        break;
      else
        s[i + p[i]] = c[i];
    if (i < n)
      cout << -1;
    else {
      cout << s[0];
      for (int i = 1; i < n; ++i)
        cout << ' ' << s[i];
    }
    cout << '\n';
  }

  return 0;
}
