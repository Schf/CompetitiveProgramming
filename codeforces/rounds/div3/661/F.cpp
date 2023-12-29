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
	while (cin >> n)
	{
		vector <pair <ll, ll>> id (n), ls (n), rs (n);
		for (i = 0; i < n; ++i)
			id[i].f = id[i].s = ls[i].s = rs[i].s = i,
			cin >> ls[i].f >> rs[i].f;
		sort (ls.begin (), ls.end (), [&] (auto & a, auto & b)
		{
			if (a.f == b.f) return rs[id[a.s].s] < rs[id[b.s].s];
			return a.f < b.f;
		});
		for (i = 0; i < n; ++i)
			id[ls[i].s].f = i;
		sort (rs.begin (), rs.end (), [&] (auto & a, auto & b)
		{
			if (a.f == b.f) return ls[id[a.s].f] < ls[id[b.s].f];
			return a.f < b.f;
		});
		for (i = 0; i < n; ++i)
			id[rs[i].s].s = i;

		/*
		vector <vector <ll>> graph (n);
		for (i = 0; i < n; ++i)
		{
			for (j = i + 1; j < n; ++j)
			{
				if (i == j) continue;
				if (inp[i].s < inp[j].f || inp[i].f > inp[j].s || 
						(inp[i].f <= inp[j].f && inp[i].s >= inp[j].s) ||
						(inp[i].f >= inp[j].f && inp[i].s <= inp[j].s))
					graph[i].push_back (j),
					graph[j].push_back (i);
			}
		}
		for (i = 0; i < graph.size (); ++i)
		{
			cout << i << ": ";
			trav (a, graph[i]) cout << a << ' ';
			cout << '\n';
		}*/
	}

	return 0;
}

