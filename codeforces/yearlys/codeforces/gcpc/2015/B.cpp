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
	vector <vector <ll>> graph (n), igraph (n);
	for (i = 0; i < n; ++i)
	{
		ll k; cin >> k;
		graph[i].resize (k);
		trav (v, graph[i])
			cin >> v,
			igraph[v].push_back (i);
	}

	vector <ll> topo (n), t (n);
	for (i = 0; i < n; ++i)
		if (!graph[i].size ())
			topo[i] = 0;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			trav (v, graph[j])
				topo[j] = max (topo[j], topo[v] + 1);
	iota (t.begin (), t.end (), 0);
	sort (t.rbegin (), t.rend (), [&] (auto a, auto b)
		{ return topo[a] < topo[b]; });

	trav (v, graph)
		sort (v.rbegin (), v.rend (), [&] (auto a, auto b)
			{return topo[a] < topo[b]; });
	trav (v, igraph)
		sort (v.rbegin (), v.rend (), [&] (auto a, auto b)
			{return topo[a] < topo[b]; });

	/*for (i = 0; i < n; ++i)
	{
		cout << i << ": ";
		trav (v, graph[i])
			cout << v << ' ';
		cout << '\n';
	}
	cout << "-------------\n";
	for (i = 0; i < n; ++i)
	{
		cout << i << ": ";
		trav (v, igraph[i]) cout << v << ' ';
		cout << '\n';
	}
	cout << "============================\n";*/

	queue <ll> go;
	vector <ll> viz (n);
	ll ans = 0;
	for (i = j = 0; i < n; ++i)
		if (igraph[t[i]].empty ())
			go.push (t[i]), viz[t[i]] = ++ans;
	while (!go.empty ())
	{
		ll cur = go.front ();
		go.pop ();
		//cout << cur << ' ' << graph[cur].size () << '\n';
		while (graph[cur].size ())
		{
			ll nxt = graph[cur][0];
			for (i = 0; i < n; ++i)
			{
				if (find (graph[i].begin (), graph[i].end (), cur) != graph[i].end ())
					graph[i].erase (find (graph[i].begin (), graph[i].end (), cur));
				if (find (igraph[i].begin (), igraph[i].end (), cur) != igraph[i].end ())
				{
					igraph[i].erase (find (igraph[i].begin (), igraph[i].end (), cur));
					if (i != nxt && !igraph[i].size ())
						go.push (i),
						viz[i] = ++ans;
				}
			}
			graph[cur].clear ();
			igraph[cur].clear ();
			/*for (i = 0; i < n; ++i)
			{
				cout << i << ": ";
				trav (v, graph[i])
					cout << v << ' ';
				cout << '\n';
			}
			cout << "-------------\n";
			for (i = 0; i < n; ++i)
			{
				cout << i << ": ";
				trav (v, igraph[i]) cout << v << ' ';
				cout << '\n';
			}
			cout << "============================\n";*/
			viz[nxt] = viz[cur];
			cur = nxt;
		}
	}
	//for (i = 0; i < n; ++i)
	//	cout << '<' << i << ' ' << viz[i] << "> ";
	//cout << '\n';
	cout << ans << '\n';

	return 0;
}

