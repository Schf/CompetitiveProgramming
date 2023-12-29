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
  ll i, j, n, TC;
  cin >> TC;
  while (TC--) {
    ll a, b, p;
    cin >> a >> b >> p;

    string s;
    cin >> s;
    s[s.size() - 1] = 'C';

    for (i = s.size() - 2; i >= 0; --i) {
      if (s[i] != s[i + 1]) {
        if (s[i] == 'A')
          p -= a;
        else
          p -= b;
      }
      if (p < 0)
        break;
    }

    cout << i + 2 << '\n';
  }

  return 0;
}
