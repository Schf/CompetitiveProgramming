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
vector <ll> vol;
vector <pair <ll, ll>> viz;
ll i, j, n, m, k, s, t;

void dfs (ll tgt)
{
	viz[tgt].f = 1;
	trav (v, graph[tgt])
		if (!viz[v].f)
			viz[v].f = 1,
			dfs (v);
}

bool can (ll test)
{
	viz.assign (viz.size (), {INF, -1});
	auto avol = vol;
	ll ss = s, tt = t;
	for (ll qq = 0; ss != tt && avol[ss]; ++qq)
	{
		viz[ss] = {0, qq};
		avol[ss] = 0;
		queue <ll> bfs;
		bfs.push (ss);
		while (!bfs.empty ())
		{
			ll cur = bfs.front ();
			bfs.pop ();
			if (viz[cur].f > test)
				return false;
			if (avol[cur] || cur == tt)
			{
				ss = cur;
				break;
			}
			trav (v, graph[cur])
				if (viz[v].s != qq || viz[v].f > viz[cur].f + 1)
					viz[v] = {viz[cur].f + 1, qq},
					bfs.push (v);
		}
	}
	if (viz[ss].f > test) return false;
	else return true;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cin >> n >> m >> k;
	graph.resize (n);
	viz.resize (n, {0, 0});
	vol.resize (n, 0);
	for (i = 0; i < k; ++i)
		cin >> j, vol[j - 1] = 1;
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
		graph[b].push_back (a);
	}
	ll ans = 0;
	cin >> s >> t; --s, --t;

	dfs (s);
	if (!viz[t].f)
	{
		cout << "-1\n";
		return 0;
	}

	ll step = n/2, current = 0;
	for (; step > 0; step /= 2)
		while (!can (current + step)) current += step;
	cout << current + 1 << '\n';

	return 0;
}

