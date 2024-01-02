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

void djk(ll tgt, vector<pll> &viz, vector<vector<pll>> &graph) {
  set<pll> pq;
  pq.insert({0, tgt});
  while (pq.size()) {
    pll cur = *pq.begin();
    pq.erase(pq.begin());
    if (viz[cur.s].s > cur.f) {
      viz[cur.s].s = cur.f;
      trav(child, graph[cur.s]) if (child.f != tgt)
          pq.insert({cur.f + child.s, child.f});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, m, T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vll bikes(n);
    vector<vector<pll>> g(n), dm(n, vector<pll>(n, {0, INFLL}));
    for (i = 0; i < m; ++i) {
      ll a, b, w;
      cin >> a >> b >> w;
      --a, --b;
      g[a].push_back({b, w});
      g[b].push_back({a, w});
    }
    for (i = 0; i < n; ++i)
      for (j = 0, cin >> bikes[i]; j < n; ++j)
        dm[i][j].f = j;
    for (i = 0; i < n; ++i) {
      djk(i, dm[i], g);
    }
    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        dm[i][j].s *= bikes[i];
    // cout << "    ";
    // for (i = 0; i < n; ++i)
    //   cout << setw(3) << i + 1 << ' ';
    // cout << "\n   ";
    // for (i = 0; i < n; ++i)
    //   cout << "____";
    // cout << '\n';
    // for (i = 0; i < n; ++i) {
    //   cout << setw(2) << i + 1 << "| ";
    //   trav(e, dm[i]) cout << setw(3) << e.s << ' ';
    //   cout << '\n';
    // }
    vector<pll> w(n, {0, INFLL});
    for (i = 0; i < n; ++i)
      w[i].f = i;
    djk(0, w, dm);
    cout << w[n - 1].s << '\n';
    // cout << setw(2) << 1 << "| ";
    // trav(e, w) cout << setw(3) << e.s << ' ';
    // cout << '\n';
    // cout << '\n';
  }

  return 0;
}
