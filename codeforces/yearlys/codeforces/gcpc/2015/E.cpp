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

vector <vector <pair <ll, ll>>> graph;
vector <vector <ll>> prnt;
vector <ll> viz, cpath;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, k;
	cin >> n >> m >> k;
	graph.resize (n);
	prnt.resize (n);
	viz.resize (n, INF);
	cpath.resize (k);
	trav (a, cpath) cin >> a, --a;
	for (i = 0; i < m; ++i)
	{
		ll a, b, p;
		cin >> a >> b >> p;
		--a, --b;
		graph[a].push_back ({b, p});
		graph[b].push_back ({a, p});
	}

	set <pair <ll, ll>> djk;
	viz[0] = 0;
	trav (p, graph[0])
		djk.insert ({p.s, p.f}),
		viz[p.f] = p.s,
		prnt[p.f].push_back (0);

	while (!djk.empty ())
	{
		auto c = *djk.begin ();
		djk.erase (djk.begin ());

		trav (p, graph[c.s])
			if (viz[p.f] == viz[c.s] + p.s)
				prnt[p.f].push_back (c.s);
			else if (viz[p.f] > viz[c.s] + p.s)
				viz[p.f] = viz[c.s] + p.s,
				djk.insert ({viz[p.f], p.f}),
				prnt[p.f].assign (1, c.s);
	}
	for (i = 0; i < n; ++i)
	{
		trav (p, graph[i])
			if (viz[p.f] == viz[i] + p.s)
				if (find (prnt[p.f].begin (), prnt[p.f].end (), i) == prnt[p.f].end ())
					prnt[p.f].push_back (i);
	}
	/*cout << "0: \n";
	for (i = 1; i < n; ++i)
	{
		cout << i+1 << ": ";
		trav (a, prnt[i]) cout << a+1 << ' ';
		cout << '\n';
	}
	for (i = 0; i < n; ++i)
		cout << i+1 << ": " << viz[i] << " | ";
	cout << '\n';*/
	bool ok = false;
	for (i = cpath.size () - 1; i >= 0; --i)
		if (prnt[cpath[i]].size () > 1) ok = true;
	if (ok) cout << "yes\n";
	else cout << "no\n";

	return 0;
}

