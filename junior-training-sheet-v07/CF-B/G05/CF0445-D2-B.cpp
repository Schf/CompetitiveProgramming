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

vector <vector <ll>> graph;
vector <ll> viz;

void dfs (ll tgt)
{
	trav (v, graph[tgt])
		if (!viz[v])
			viz[v] = viz[tgt],
			dfs (v);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	graph.resize (n);
	viz.resize (n);
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
		graph[b].push_back (a);
	}
	for (i = j = 0; i < n; ++i)
	{
		if (viz[i]) continue;
		viz[i] = ++j;
		dfs (i);
	}

	cout << (1LL << (n - j)) << '\n';

	return 0;
}

