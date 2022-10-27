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
vector <ll> spec, spec_vec;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, k;
	cin >> n >> m >> k;
	graph.resize (n);
	spec.resize (n, -1);
	spec_vec.resize (k);
	for (i = 0; i < k; ++i)
		cin >> j, spec[j - 1] = i, spec_vec[i] = j - 1;
	for (i = 0; i < m; ++i)
	{
		ll a, b, p;
		cin >> a >> b >> p;
		--a, --b;
		graph[a].push_back ({b, p});
		if (a != b)
			graph[b].push_back ({a, p});
	}
	trav (a, spec_vec) cout << a << ' ';
	cout << '\n';
	trav (v, graph)
	{
		trav (p, v)
			cout << p.f << ' ' << p.s << " | ";
		cout << '\n';
	}
	vector <ll> dists (n, -INF);
	queue <ll> bfs;
	bfs.push (spec_vec[0]);
	dists[spec_vec[0]] = 0;
	while (!bfs.empty ())
	{
		ll cur = bfs.front ();
		bfs.pop ();
		trav (v, graph[cur])
			if (v.s > dists[v.f])
				dists[v.f] = v.s,
				bfs.push (v.f);
	}
	ll ans = 0;
	for (i = 0; i < k; ++i)
		ans = max (ans, dists[spec_vec[i]]);
	for (i = 0; i < k; ++i)
		cout << ans << ' ';
	cout << '\n';

	return 0;
}

