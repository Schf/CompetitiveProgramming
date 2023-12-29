#include <bits/stdc++.h>
#include <cstring>
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
    vll rank(n, -1), a(2 * n);
    vector<pll> inp(2 * n), b(n);
    for (i = 0; i < n; ++i)
      cin >> inp[2 * i].f >> inp[2 * i + 1].f,
          inp[2 * i].s = inp[2 * i + 1].s = i;
    sort(inp.begin(), inp.end());
    for (i = j = 0; i < 2 * n; ++i)
      if (rank[inp[i].s] < 0)
        a[i] = j, b[a[i]].f = i, rank[inp[i].s] = j++;
      else
        a[i] = rank[inp[i].s], b[a[i]].s = i;

    // for (i = 0; i < 2 * n; ++i)
    //   cout << a[i] << ' ';
    // cout << '\n';
    // for (i = 0; i < n; ++i)
    //   cout << '<' << b[i].f << ", " << b[i].s << "> ";
    // cout << '\n';
    // continue;
    ll ret = 0;
    vll tree(1 << (8 * sizeof(n) - __builtin_clzll(n - 1) + 1));
    // for (i = 0; i < tree.size() / 2; ++i)
    //   cout << "- ";
    // for (i = 0; i < tree.size() / 2; ++i)
    //   cout << i << ' ';
    // cout << '\n';
    for (i = 0; i < 2 * n; ++i) {
      if (b[a[i]].f == i)
        for (j = a[i] + tree.size() / 2; j > 0; j >>= 1)
          tree[j]++;
      else {
        for (j = a[i] + tree.size() / 2; j > 0; j >>= 1)
          tree[j]--;
        for (ll l = tree.size() / 2, r = a[i] + tree.size() / 2; l < r;
             l >>= 1, r >>= 1) {
          if (l & 1)
            ret += tree[l++];
          if (r & 1)
            ret += tree[--r];
        }
      }
      // for (j = 0; j < tree.size(); ++j)
      //   cout << tree[j] << ' ';
      // cout << "| " << ret << '\n';
    }
    cout << ret << '\n';
    // cout << "-----------------------------------------------\n";
  }

  return 0;
}
