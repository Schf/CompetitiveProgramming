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
const ll MAXN = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, TC;
  vll p(MAXN), c(5);

  cin >> TC;
  for (int TCi = 1; TCi <= TC; ++TCi) {
    cout << "Case #" << TCi << ":\n";
    memset(&p[0], 0, p.size() * sizeof p[0]);
    memset(&c[0], 0, c.size() * sizeof c[0]);
    for (int k = 0; k < 3; ++k) {
      cin >> j;
      for (i = 0; i < j; ++i) {
        ll a;
        cin >> a;
        if (p[a])
          p[a] = 4;
        else
          p[a] = k + 1;
      }
    }
    for (i = 0; i < MAXN; ++i)
      c[p[i]]++;
    j = *max_element(c.begin() + 1, c.end() - 1);
    for (int k = 1; k <= 3; ++k) {
      if (c[k] < j)
        continue;
      cout << k << ' ' << c[k];
      for (i = 0; i < MAXN; ++i)
        if (p[i] == k)
          cout << ' ' << i;
      cout << '\n';
    }
  }

  return 0;
}
