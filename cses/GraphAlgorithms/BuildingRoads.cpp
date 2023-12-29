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

void dfs (int tgt)
{
	viz[tgt] = 1;
	trav (v, graph[tgt])
		if (!viz[v])
			dfs (v);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	graph.resize (n);
	viz.resize (n, 0);
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
		graph[b].push_back (a);
	}
	vector <ll> cons;
	for (i = 0; i < n; ++i)
	{
		if (viz[i]) continue;
		cons.push_back (i);
		dfs (i);
	}
	cout << cons.size () - 1 << '\n';
	for (i = 1; i < cons.size (); ++i)
		cout << cons[0] + 1 << ' ' << cons[i] + 1 << '\n';

	return 0;
}


