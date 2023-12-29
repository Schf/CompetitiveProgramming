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

  ll t;
  cin >> t;
  while (t--) {
    cin >> n;
    vll v(n);
    trav(a, v) cin >> a;
    for (j = i = 0; i < v.size(); ++i)
      if (v[i] < v[j])
        j = i;
    v[j]++;
    n = 1;
    for (i = 0; i < v.size(); ++i)
      n *= v[i];
    cout << n << endl;
  }

  return 0;
}
