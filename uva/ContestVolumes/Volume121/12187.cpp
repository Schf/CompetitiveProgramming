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

#define INB(a, b, r, c) ((0 <= (a)) && ((a) < r) && (0 <= (b)) && ((b) < c))

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, r, c, k;
  vector<vll> g(100, vll(100)), cc;
  while (cin >> n >> r >> c >> k, n) {
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> g[i][j];
    cc = g;
    for (int ki = 0; ki < k; ++ki) {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          int conq = (g[i][j] - 1 + n) % n;

          for (int delta = -1; delta < 2; delta += 2) {

            if (INB(i + delta, j, r, c))
              if (g[i + delta][j] == conq)
                cc[i][j] = conq;

            if (INB(i, j + delta, r, c))
              if (g[i][j + delta] == conq)
                cc[i][j] = conq;
          }
        }
      }
      g = cc;
    }
    for (int i = 0; i < r; ++i) {
      cout << g[i][0];
      for (int j = 1; j < c; ++j)
        cout << ' ' << g[i][j];
      cout << '\n';
    }
  }

  return 0;
}
