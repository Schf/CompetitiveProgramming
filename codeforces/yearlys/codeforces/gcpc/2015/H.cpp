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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	map <string, ll> stn;
	vector <vector <ll>> graph (n);
	map <string, vector <string>> input;
	for (i = 0; i < n; ++i)
	{
		ll k;
		string s;
		cin >> s >> k;
		input[s].resize (k);
		for (j = 0; j < k; ++j)
			cin >> input[s][j];
	}
	i = 0;
	trav (o, input)
		stn[o.f] = i++;
	trav (o, input)
		trav (s, o.s)
			graph[stn[s]].push_back (stn[o.f]);

	queue <ll> bfs;
	vector <bool> viz (n);
	trav (p, stn)
		if (p.f.substr (max (0LL, (ll)p.f.size () - 9LL)) == "::PROGRAM")
			bfs.push (p.s), viz[p.s] = 1;

	while (!bfs.empty ())
	{
		ll cur = bfs.front ();
		bfs.pop ();
		trav (v, graph[cur])
			if (!viz[v])
				viz[v] = true, bfs.push (v);
	}

	ll ans = 0;
	for (i = 0; i < n; ++i)
		ans += 1 - viz[i];
	cout << ans << '\n';

	return 0;
}

