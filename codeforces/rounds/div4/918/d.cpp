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
    cin >> n;
    string s;
    cin >> s;
    vll vowel('e' + 1);
    vowel['a'] = vowel['e'] = 1;
    cout << s.substr(0, 2);
    for (i = 2; i + 1 < s.size(); ++i) {
      if (vowel[s[i]])
        cout << s[i];
      else if (vowel[s[i + 1]])
        cout << '.' << s[i];
      else
        cout << s[i];
    }
	if (n > 2)
		cout << s[n - 1];
	cout << '\n';
  }

  return 0;
}
