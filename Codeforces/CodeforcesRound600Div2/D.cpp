#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef int ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

vector <vector <ll>> graph;
vector <set <ll>> cgraph;
vector <ll> viz, cviz;

void dfs (ll cur)
{
	trav (v, graph[cur])
		if (!viz[v])
			viz[v] = viz[cur],
			dfs (v);
}

void cdfs (ll cur)
{
	trav (v, cgraph[cur])
		if (!cviz[v])
			cviz[v] = cviz[cur],
			cdfs (v);
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
	trav (a, viz) --a;
	vector <vector <ll>> comps (j);
	for (i = 0; i < n; ++i)
		comps[viz[i]].push_back (i);
	trav (v, comps) sort (v.begin (), v.end ());
	sort (comps.begin (), comps.end (), [&] (auto & a, auto & b)
	{
		if (a.back () - a[0] == b.back () - b[0]) return a[0] < b[0];
		return a.back () - a[0] > b.back () - b[0];
	});
	for (i = 0; i < comps.size (); ++i)
		for (j = 0; j < comps[i].size (); ++j)
			viz[comps[i][j]] = i;
	cgraph.resize (comps.size ());
	cviz.resize (comps.size ());
	vector <ll> org (comps.size (), INF), ord;
	for (i = 1; i < n; ++i)
	{
		if (viz[i - 1] != viz[i])
			ord.push_back (viz[i - 1]),
			org[viz[i - 1]] = ord.size ();
		for (; org[viz[i]] < ord.size ();
				org[viz[i]] = max (org[viz[i]] + 1, org[ord[org[viz[i]]]]))
			if (viz[i] != ord[org[viz[i]]])
				cgraph[viz[i]].insert (ord[org[viz[i]]]);
	}
	/*for (i = 0; i < comps.size (); ++i)
	{
		if (comps[i].back () - comps[i][0] + 1 == comps[i].size ())
			continue;
		for (j = 0; j + 1 < comps[i].size (); ++j)
			for (ll k = comps[i][j] + 1; k < comps[i][j + 1]; ++k)
				cgraph[i].insert (viz[k]),
				cgraph[viz[k]].insert (i);
	}*/
	/*for (i = 0; i < cgraph.size (); ++i)
	{
		cout << i << ": ";
		trav (a, cgraph[i]) cout << a << ' ';
		cout << '\n';
	}*/
	for (i = j = 0; i < comps.size (); ++i)
	{
		if (cviz[i]) continue;
		cviz[i] = ++j;
		cdfs (i);
	}
	trav (a, cviz) --a;
	vector <vector <ll>> ccomps (j);
	for (i = 0; i < comps.size (); ++i)
		ccomps[cviz[i]].push_back (i);
	ll ans = 0;
	trav (v, ccomps) ans += v.size () - 1;
	cout << ans << '\n';

	return 0;
}

