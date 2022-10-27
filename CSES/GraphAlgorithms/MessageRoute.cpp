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
	queue <ll> bfs;
	vector <ll> viz (n, INF);
	bfs.push (0);
	viz[0] = 1;
	while (!bfs.empty ())
	{
		ll cur = bfs.front ();
		bfs.pop ();
		trav (v, graph[cur])
			if (viz[v] > viz[cur] + 1)
				viz[v] = viz[cur] + 1, bfs.push (v);
	}
	if (viz[n - 1] >= INF)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector <ll> path (1, n);
	for (j = n - 1; j > 0;)
	{
		trav (v, graph[j])
			if (viz[v] < viz[j])
				path.push_back (v + 1), j = v;
	}
	cout << path.size () << '\n';
	for (i = path.size () - 1; i >= 0; --i)
		cout << path[i] << ' ';
	cout << '\n';

	return 0;
}


