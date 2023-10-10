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
    string s;
    cin >> s;
    vll stk(s.size() + 2);
    stk[0] = (s[0] == 'A');
    for (i = 1; i < s.size(); i++)
      stk[i] = (s[i] == 'A') * (stk[i - 1] + 1);
    for (i = s.size() - 2; i >= 0; i--)
      if (i >= 0 && i + 1 < s.size()) {
        if (s[i] == 'A' && s[i + 1] == 'A')
          stk[i] = stk[i + 1];
      } else
        break;
    ll has_db = 0, min_seq = (s[0] == 'B') * INFLL + stk[0], sum = 0;
    for (i = 1; i < s.size(); i++) {
      if (s[i] == 'B') {
        sum += stk[i - 1];
        if (s[i - 1] == 'B')
          has_db = 1;
      }
      if (s[i] == 'A')
        min_seq = min(min_seq, stk[i]);
    }
    if (s[s.size() - 1] == 'A')
      sum += stk[s.size() - 1];
    if (s[0] != 'B' && s[s.size() - 1] != 'B' && !has_db && sum)
      sum -= min_seq;
    cout << sum << endl;
  }

  return 0;
}
