#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	ll COUNT = 1;
	while (n || m)
	{
		vector <vll> graph (n);
		for (i = 0; i < n; ++i)
			graph[i].push_back (i);
		for (i = 0; i < m; ++i)
		{
			ll a, b;
			cin >> a >> b;
			--a, --b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		trav (v, graph)
			sort(v.begin (), v.end ());

		ll ans = 0;
		vll viz (n, 0), ansv (n, 0);
		for (i = 0; i < n; ++i)
		{
			viz[i] = 1;
			if (graph[i][graph[i].size()-1] <= i) continue;
			trav(v, graph[i])
				if (!viz[v])
					ans += (graph[i] == graph[v]),
					ansv[i] += (graph[i] == graph[v]);
		}
		
		cout << ans << '\n';
		cin >> n >> m;
	}

	return 0;
}
