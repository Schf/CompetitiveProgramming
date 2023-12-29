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
	vector <ll> viz (n, 0);
	queue <ll> bfs;
	for (i = 0; i < n; ++i)
	{
		if (viz[i]) continue;
		viz[i] = 1;
		bfs.push (i);
		while (!bfs.empty ())
		{
			ll a = bfs.front ();
			bfs.pop ();
			trav (v, graph[a])
				if (viz[v] == viz[a]) goto out;
				else if (viz[v] == 0) viz[v] = 3 - viz[a], bfs.push (v);
		}
	}
	out:;
	if (i >= n) trav (a, viz) cout << a << ' ';
	else cout << "IMPOSSIBLE";
	cout << '\n';

	return 0;
}


