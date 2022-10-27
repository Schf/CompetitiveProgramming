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

ll dfs (ll tgt = 0)
{
	bool end = true;
	ll ret = -1;
	trav (v, graph[tgt])
		if (!viz[v])
			end = false,
			viz[v] = viz[tgt] + 1,
			ret = dfs (v);
	if (end) return tgt;
	else return ret;
}

ll center ()
{
	viz.assign (graph.size (), 0);
	viz[0] = 1;
	ll mx = dfs (0);
	viz.assign (graph.size (), 0);
	viz[mx] = 1;
	dfs (mx);
	mx = 0;
	for (ll i = 0; i < graph.size (); ++i)
		if (viz[mx] < viz[i])
			mx = i;
	if (!(viz[mx] & 1))
		return -1;
	ll cur_v = mx;
	for (ll i = 0; i < viz[mx]/2; ++i)
		trav (v, graph[cur_v])
			if (viz[v] < viz[cur_v])
			{
				cur_v = v;
				break;
			}
	return cur_v;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, k;
	cin >> n >> k;
	graph.resize (n);
	viz.resize (n, 0);
	for (i = 0; i < n - 1; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
		graph[b].push_back (a);
	}
	trav (v, graph)
		sort (v.begin (), v.end ());
	ll cc = center ();
	if (cc < 0)
	{
		cout << "No\n";
		return 0;
	}
	queue <pair <ll, ll>> bfs;
	bfs.push ({cc, 2});
	viz.resize (graph.size (), 0);
	while (!bfs.empty ())
	{
		ll cur = bfs.front ().f;
		ll k = bfs.front ().s;
		bfs.pop ();
		if ((k == 0 && graph[cur].size () > 1) ||
				(k != 0 && graph[cur].size () < 3))
		{
			cout << "No\n";
			return 0;
		}
		trav (v, graph[cur])
			if (!viz[v])
				viz[v] = 1,
				bfs.push ({v, k - 1});
	}
	cout << "Yes\n";

	return 0;
}
