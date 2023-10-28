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
  vll id(52);
  vector<string> ac(52), nm(52);

  while (cin >> n, n) {
    for (i = 0; i < n; ++i)
      cin >> ac[i] >> nm[i], id[i] = -1;
    for (i = 0, j = -1; i < n; ++i) {
      for (int k = 0; k < nm[i].size(); ++k) {
        do {
          j = (j + 1) % n;
        } while (id[j] != -1);
      }
      id[j] = i;
    }
    cout << ac[id[0]];
    for (i = 1; i < n; ++i)
      cout << ' ' << ac[id[i]];
    cout << '\n';
  }

  return 0;
}
