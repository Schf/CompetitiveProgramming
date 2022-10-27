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

vector <vector <ll>> graph, comp;
vector <ll> viz, gov;

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
	ll i, j, n, m, k;
	cin >> n >> m >> k;
	graph.resize (n);
	viz.resize (n, 0);
	gov.resize (n, 0);
	for (i = 0; i < k; ++i)
		cin >> j, gov[--j] = 1;
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
	comp.resize (j);
	for (i = 0; i < n; ++i)
		comp[viz[i] - 1].push_back (i);
	vector <ll> free_comps (comp.size (), 1);
	for (i = 0; i < n; ++i)
		if (gov[i])
			free_comps[viz[i] - 1] = 0;
	ll big_comp = -1;
	for (i = 0; i < comp.size (); ++i)
		if (!free_comps[i])
			if (big_comp < 0 || comp[big_comp].size () < comp[i].size ())
				big_comp = i;
	ll ans = 0, sum = 0;
	for (i = 0; i < comp.size (); ++i)
		if (!free_comps[i] && i != big_comp)
			ans += comp[i].size ()*(comp[i].size () - 1)/2;
		else sum += comp[i].size ();
	ans += sum*(sum - 1)/2;
	ans -= m;
	cout << ans << '\n';

	return 0;
}

