#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

vector <pair <pair <ll, ll>, ll>> inp;
vector <pair <ll, vector <ll>>> graph;
vector <ll> viz;

ll dfs (ll tgt)
{
	if (tgt < 0 || tgt >= graph.size ()) return 0;
	if (viz[tgt] >= 0) return viz[tgt];
	ll ans = 0;
	trav (v, graph[tgt].s)
		ans = max (ans, graph[v].f + dfs (v));
	return (viz[tgt] = ans);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		inp.resize (n);
		graph.resize (n);
		viz.resize (n, -1);
		trav (pp, inp) cin >> pp.f.f >> pp.f.s >> pp.s;
		sort (inp.begin (), inp.end ());
		for (i = 0; i < n; ++i)
		{
			graph[i].f = inp[i].s;
			ll ub = n - 1, lb = i + 1, mb = (ub + lb) / 2;
			while (ub - lb > 1 && 0 <= mb && mb < inp.size ())
			{
				if (inp[mb].f.f <= inp[i].f.s) lb = mb;
				else ub = mb;
				mb = (ub + lb) / 2;
			}
			for (j = max (i + 1, mb - 1); j < min (n, mb + 2); ++j)
				if (inp[j].f.f > inp[i].f.s) break;
			for (j = max (j, 0LL); j < n; ++j)
			{
				if (inp[j].f.f <= inp[i].f.s) continue;
				if (graph[i].s.size () && inp[j].f.f > inp[graph[i].s[0]].f.s)
					break;
				graph[i].s.push_back (j);
				if (inp[graph[i].s[0]].f.s > inp[graph[i].s.back ()].f.s)
					swap (graph[i].s[0], graph[i].s[graph[i].s.size () - 1]);
			}
		}
		ll ans = 0;
		for (i = 0; i < n; ++i)
			if (viz[i] < 0) ans = max (ans, graph[i].f + dfs (i));
			else ans = max (ans, graph[i].f + viz[i]);
		cout << ans << '\n';
	}

	return 0;
}

