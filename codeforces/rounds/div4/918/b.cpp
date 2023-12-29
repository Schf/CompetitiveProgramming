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
    vector<string> a(3);
    trav(s, a) cin >> s;
    for (i = 0; i < 3; ++i) {
      vll cc(3);
      trav(c, a[i]) cc[c - 'A']++;
      for (j = 0; j < 3; ++j)
        if (!cc[j])
          cout << (char)(j + 'A') << '\n';
    }
  }

  return 0;
}
