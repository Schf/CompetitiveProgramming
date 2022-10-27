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

void dfs (ll tgt, vector <vector <ll>> & graph, vector <ll> & viz)
{
	trav (v, graph[tgt])
		if (!viz[v])
			viz[v] = 3 - viz[tgt],
			dfs (v, graph, viz);
		else if (viz[v] == viz[tgt]) viz[v] = 3;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	vector <vector <ll>> graph (n);
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
		graph[b].push_back (a);
	}
	vector <ll> viz (n, 0);
	for (i = j = 0; i < n; ++i)
	{
		if (viz[i]) continue;
		viz[i] = 1;
		dfs (i, graph, viz);
	}
	ll ans = 0;
	trav (a, viz)
		if (a == 3)
			++ans;
	if ((n - ans)&1) ++ans;
	cout << ans << '\n';

	return 0;
}

