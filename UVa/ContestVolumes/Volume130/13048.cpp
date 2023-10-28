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
  string s;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> s;
    n = s.size();
    for (i = j = 0; i < n; ++i)
      if (!((i + 2 < n && s[i + 2] == 'B') || (i + 1 < n && s[i + 1] == 'B') ||
            (s[i] == 'B') || (s[i] == 'D') || (i - 1 >= 0 && s[i - 1] == 'S') ||
            (s[i] == 'S') || (i + 1 < n && s[i + 1] == 'S')))
        j++;
    cout << "Case " << t << ": " << j << '\n';
  }

  return 0;
}
