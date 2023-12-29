#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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

vector <vector <pair <ll, ll>>> graph;
vector <ll> viz;

void dk (ll lim)
{
	fill (viz.begin (), viz.end (), INFLL);
	viz[0] = 0;
	set <pair <ll, ll>> qq;
	qq.insert ({0, 0});
	while (!qq.empty ())
	{
		ll cur = qq.begin ()->s;
		qq.erase (qq.begin ());
		trav (v, graph[cur])
		{
			if (v.s <= lim && viz[cur] + v.s < viz[v.f])
			{
				viz[v.f] = viz[cur] + v.s;
				qq.insert ({viz[v.f], v.f});
			}
		}
	}
}

bool check (ll lim, double mn)
{
	dk (lim);
	return viz.back () <= mn;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, x;
	cin >> n >> m >> x;
	graph.resize (n);
	viz.resize (n);
	for (i = 0; i < m; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		graph[a].push_back ({b, c});
		graph[b].push_back ({a, c});
	}
	dk (INFLL);
	double mn = viz[n - 1];
	mn = mn*(100 + x)/100.0;
	ll ub = INFLL, lb = 0, mb = (ub + lb)/2;
	while (ub - lb > 1)
	{
		if (check (mb, mn)) ub = mb;
		else lb = mb;
		mb = (ub + lb)/2;
	}
	for (mb = lb - 1; mb <= ub + 1; ++mb)
		if (check (mb, mn)) break;
	cout << mb << '\n';

	return 0;
}


