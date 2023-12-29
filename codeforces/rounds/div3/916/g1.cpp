#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

const ll MOD = 998244353;
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
    vll g(n + 1, -1), gc, a(2*n);
    vector<set<ll>> gg;
    for (i = 0; i < 2 * n; ++i) {
      ll cur_num;
      cin >> cur_num;
	  a[i] = cur_num;
      ll &cur_group = g[cur_num];
      if (cur_group < 0)
        cur_group = gg.size(), gg.push_back({cur_num});
      else {
        for (; cur_group + 1 < gg.size(); gg.pop_back())
          for (auto &e : gg[gg.size() - 1])
            gg[cur_group].insert(e), g[abs(e)] = cur_group;
        gg[cur_group].erase(cur_num);
        gg[cur_group].insert(-cur_num);
        if (*gg[cur_group].rbegin() < 0) {
          if (cur_group == 0)
            gc.push_back(gg[cur_group].size());
          gg.pop_back();
        }
      }
    }
    ll r = 1;
    trav(e, gc) r = (r * e * 2) % MOD;
	cout << n << " | ";
	for (i = 0; i < 2*n; ++i)
		cout << a[i] << ' ';
    cout << "| " << gc.size() << ' ' << r << '\n';
  }

  return 0;
}
