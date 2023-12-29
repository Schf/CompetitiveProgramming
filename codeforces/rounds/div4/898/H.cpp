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

enum COLOR { WHITE = 0, GRAY, BLACK };

bool dfs(vector<vll> &graph, vll &viz, ll tgt) {
  // for(ll i = 0; i < viz.size(); ++i)
  //   cout << viz[i] << ' ';
  // cout << endl;
  for (ll i = 0; i < graph[tgt].size(); ++i)
    if (!viz[graph[tgt][i]]) {
      viz[graph[tgt][i]] = viz[tgt] + 1;
      if (dfs(graph, viz, graph[tgt][i])) {
        if (viz[graph[tgt][i]] < 0 && viz[tgt] < INF)
          viz[tgt] *= -1;
        return true;
      }
    } else if (viz[graph[tgt][i]] < viz[tgt] - 1) {
      viz[tgt] *= -1;
      viz[graph[tgt][i]] += INF;
      return true;
    }

  return false;
}

void bfs(vector<vll> &graph, vll &viz, ll tgt) {
  queue<ll> q;
  q.push(tgt);
  while (!q.empty()) {
    ll cur = q.front();
    q.pop();
    for (ll i = 0; i < graph[cur].size(); ++i) {
      if (!viz[graph[cur][i]]) {
        viz[graph[cur][i]] = viz[cur] + 1;
        q.push(graph[cur][i]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, t;

  cin >> t;
  while (t--) {

    ll a, b;
    cin >> n >> a >> b;
    a--, b--;

    vector<vll> graph(n);
    for (i = 0; i < n; ++i) {
      ll ui, vi;
      cin >> ui >> vi;
      ui--, vi--;
      graph[ui].push_back(vi);
      graph[vi].push_back(ui);
    }

    vll mar(n), val(n);
    mar[a] = 1, val[b] = 1;
    bfs(graph, mar, a);
    dfs(graph, val, b);
    for (i = 0; i < n; ++i) {
      if (mar[i] > INF)
        mar[i] = INF - mar[i];
      if (val[i] > INF)
        val[i] = INF - val[i];
    }
    ll mar_d = INF, val_d = INF;
    for (i = 0; i < n; ++i)
      if (val[i] < 0 && -val[i] < val_d)
        mar_d = abs(mar[i]), val_d = abs(val[i]);

    // for (i = 0; i < n; ++i) {
    //   cout << i << ": ";
    //   for (j = 0; j < graph[i].size(); ++j)
    //     cout << graph[i][j] << ' ';
    //   cout << endl;
    // }
    //
    // for (i = 0; i < n; ++i)
    //   cout << mar[i] << ' ';
    // cout << endl;
    // for (i = 0; i < n; ++i)
    //   cout << val[i] << ' ';
    // cout << endl;
    //
    // cout << mar_d << ' ' << val_d << endl;

    if (mar_d <= val_d)
      cout << "NO\n";
    else
      cout << "YES\n";
  }

  return 0;
}

