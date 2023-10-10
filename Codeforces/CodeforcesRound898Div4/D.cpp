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
  ll i, j, n, k, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string s;
    cin >> s;
    for (n = i = 0; i < s.size(); ++i)
      if (s[i] == 'B') {
        n++;
        for (j = i; j < s.size() && j < i + k; ++j)
          s[j] = 'W';
        i = j - 1;
      }
    cout << n << endl;
  }

  return 0;
}
