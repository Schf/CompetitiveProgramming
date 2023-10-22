#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

vector <vector <vector <ll>>> graph;
vector <vector <ll>> viz;

void dfs (ll lvl, ll tgt)
{
	trav (v, graph[lvl][tgt])
	{
		if (!viz[lvl][v])
		{
			viz[lvl][v] = viz[lvl][tgt];
			dfs (lvl, v);
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	graph.resize (m, vector <vector <ll>> (n));
	viz.resize (m, vector <ll> (n, 0));
	for (i = 0; i < m; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		--a, --b, --c;
		graph[c][a].push_back (b);
		graph[c][b].push_back (a);
	}
	for (i = 0; i < m; ++i)
	{
		for (ll j = 0, cnt = 0; j < n; ++j)
		{
			if (viz[i][j]) continue;
			viz[i][j] = ++cnt;
			dfs (i, j);
		}
	}
	ll q;
	cin >> q;
	for (i = 0; i < q; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		ll ans = 0;
		for (j = 0; j < m; ++j)
			ans += (viz[j][a] == viz[j][b]);
		cout << ans << '\n';
	}

	return 0;
}
