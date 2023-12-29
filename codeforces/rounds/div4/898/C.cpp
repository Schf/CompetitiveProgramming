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
  ll i, j, n, t;
  cin >> t;
  while (t--) {
    vector<string> v(10);
    trav(s, v) cin >> s;
    n = 0;
    for (i = 0; i < 10; ++i)
      for (j = 0; j < v[i].size(); ++j)
        if (v[i][j] == 'X')
          n += min((5 - (int)abs(i - 4.5)), (5 - (int)abs(j - 4.5)));
    cout << n << endl;
  }

  return 0;
}
