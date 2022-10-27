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
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; cin >> tc;
	while (tc--)
	{
		int i, j, n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		--s, --g, --h;
		vector <vector <pair <int, int>>> graph (n);
		vector <int> wgt_s (n, INF), wgt_m (n, INF);
		for (i = 0; i < m; ++i)
		{
			int a, b, d; cin >> a >> b >> d; --a, --b;
			graph[a].push_back ({b, d});
			graph[b].push_back ({a, d});
		}
		queue <int> djk;
		djk.push (s);
		wgt_s[s] = 0;
		while (!djk.empty ())
		{
			int cur = djk.front ();
			djk.pop ();
			trav (v, graph[cur])
				if (wgt_s[v.f] > v.s + wgt_s[cur])
					wgt_s[v.f] = v.s + wgt_s[cur], djk.push (v.f);
		}
		if (wgt_s[g] > wgt_s[h]) swap (g, h);
		
		djk.push (h);
		wgt_m[h] = 0;
		while (!djk.empty ())
		{
			int cur = djk.front ();
			djk.pop ();
			trav (v, graph[cur])
				if (wgt_m[v.f] > v.s + wgt_m[cur])
					wgt_m[v.f] = v.s + wgt_m[cur], djk.push (v.f);
		}
		
		vector <int> can;
		for (i = 0; i < t; ++i)
		{
			int tgt; cin >> tgt; --tgt;
			if (wgt_s[tgt] == wgt_m[s] + wgt_m[tgt]) can.push_back (tgt);
		}
		sort (can.begin (), can.end ());
		trav (a, can) cout << a + 1 << ' ';
		cout << '\n';
	}

	return 0;
}

