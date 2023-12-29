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

pll fill(ll tgt, vector<vll> &aa, vector<vector<pll>> &s) {
  pll ret = {1, 0};
  // printf("% 3d ", (int)tgt + 1);
  for (; aa[tgt].size() == 1; tgt = aa[tgt][0])
    ret.f++;
  ret.s = s.size();
  // printf("% 3d % 3d % 3d\n", (int)tgt + 1, (int)ret.f, (int)ret.s);
  if (aa[tgt].size() > 1) {
    s.emplace_back();
    pll temp;
    trav(child,
         aa[tgt]) /* printf("% 3d ->% 3d | ", (int)tgt + 1, (int)child + 1), */
        temp = fill(child, aa, s),
        s[ret.s].push_back(temp), ret.f += temp.f;
    sort(s[ret.s].rbegin(), s[ret.s].rend());
  } else
    ret.s = -1;
  return ret;
}

ll calc(ll tgt, vector<vector<pll>> &s) {
  if (tgt < 0)
    return 0;
  ll sum = 0;
  for (ll i = 1; i < s[tgt].size(); ++i)
    sum += s[tgt][i].f;
  if (sum >= s[tgt][0].f)
    return (sum + s[tgt][0].f) / 2;
  ll ep = calc(s[tgt][0].s, s);
  return sum + min(s[tgt][0].f - sum, ep * 2) / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, T;
  cin >> T;
  while (T--) {
    cin >> n;
    vll a(n);
    vector<vll> aa(n);
    vector<vector<pll>> s;
    a[0] = 0;
    for (i = 1; i < n; ++i)
      cin >> a[i], a[i]--, aa[a[i]].push_back(i);
    // printf("  X ->  1 | ");
    fill(0, aa, s);
	if (s.size())
		cout << calc(0, s) << '\n';
	else cout << 0 << '\n';
    // for (i = 0; i < s.size(); ++i) {
    //   cout << i << " | ";
    //   trav(p, s[i]) cout << '<' << p.f << ", " << p.s << "> ";
    //   cout << '\n';
    // }
  }

  return 0;
}
