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

bool pali(string s) {
  for (int i = 0; i < s.size() / 2; ++i)
    if (s[i] != s[s.size() - i - 1])
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    string a, b, c;
    for (i = j = 0; i < 2 * n - 2; ++i) {
      cin >> c;
      if (c.size() > j)
        j = c.size(), a = c;
      else if (c.size() == j)
        b = c;
    }
    if (a.substr(1, a.size() - 1) != b.substr(0, b.size() - 1))
      swap(a, b);
    if (a[0] == b[b.size() - 1] && pali(a.substr(1, a.size() - 1)))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
