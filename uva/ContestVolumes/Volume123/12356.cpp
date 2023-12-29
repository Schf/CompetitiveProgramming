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
  ll i, j, n, s, b;

  while (cin >> s >> b, s > 0 && b > 0) {
    vll v(3 * s);
    for (int i = 0; i < s; ++i)
      v[3 * i] = i - 1, v[3 * i + 1] = i, v[3 * i + 2] = i + 1;
    v[3 * s - 1] = -1;
    for (int i = 0; i < b; ++i) {
      ll l, r;
      cin >> l >> r;
      l--, r--;

      int rrn = v[3*r + 2];
      int lln = v[3*l];
      if (rrn > 0)
        v[3*rrn] = lln;
      if (lln >= 0)
        v[3*lln + 2] = rrn;

      if (lln >= 0)
        cout << lln + 1 << ' ';
      else
        cout << '*' << ' ';
      if (rrn >= 0)
        cout << rrn + 1 << '\n';
      else
        cout << '*' << '\n';
    }
    cout << "-\n";
  }

  return 0;
}
