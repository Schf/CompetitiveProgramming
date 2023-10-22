#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

vector <vector <ll>> graph;
vector <ll> viz;

ll dfs (ll tgt, ll src, ll sz)
{
	if (tgt == src && viz[tgt]) return 1;
	trav (v, graph[tgt])
	{
		if (viz[v] < 0 && !(v == tgt && sz < 3))
		{
			viz[v] = tgt;
			dfs (v, src, sz + 1);
		}
	}
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	graph.resize (n);
	for (i = 0 ; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
		graph[b].push_back (a);
	}
	viz.resize (n, -1);
	for (i = 0; i < n; ++i)
	{
		if (viz[i] >= 0) continue;
		ll sz = dfs (i, i, 1);
		if (sz >= 3)
		{
			cout << sz << '\n';
			ll cur = viz[i];
			cout << i + 1 << ' ';
			while (cur != i)
				cout << cur << ' ', cur = viz[cur];
			cout << '\n';
			break;
		}
	}

	return 0;
}


