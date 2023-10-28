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
  string s;

  while (cin >> s) {
    n = s.size();
    vll pf(n, INF), sf(n, INF);
    pf[0] = s[0] == 'X' ? -1 : INF;
    sf[n - 1] = s[n - 1] == 'X' ? -1 : INF;
    for (int i = 1; i < n; ++i)
      pf[i] = s[i] == 'X' ? -1 : pf[i - 1] + 1,
      sf[n - i - 1] = s[n - i - 1] == 'X' ? -1 : sf[n - i] + 1;
    for (int i = 0; i < n; ++i)
      pf[i] = min(pf[i], sf[i]);
    cout << *max_element(pf.begin(), pf.end()) << '\n';
  }

  return 0;
}
