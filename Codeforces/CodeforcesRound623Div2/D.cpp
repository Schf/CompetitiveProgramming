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
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n;
		cin >> n;
		vector <vector <int>> costs (1e5 + 1);
		vector <int*> nps;
		vector <int> ns;
		map <int, int**> occ;
		//map <int, multiset <int>> given;
		vector <pair <int, int>> temp (n);
		trav (p, temp) cin >> p.f;
		trav (p, temp) cin >> p.s;
		trav (p, temp) costs[p.s].push_back (p.f);
		//trav (p, temp) given[p.f].insert (p.s);
		ll ans = 0;
		for (i = 1e5; i > 0; --i)
		{
			if (!costs[i].size ())
				continue;
			for (j = 0; j < costs[i].size (); ++j)
			{
				auto & ref = occ[costs[i][j]];
				auto & nexref = occ[costs[i][j] + 1];
				
				if (ref == NULL)
				{
					auto & befref = occ[costs[i][j] - 1];
					auto & nexref = occ[costs[i][j] + 1];
					ns.push_back (costs[i][j] + 1);
					nps.push_back (& (ns[ns.size () - 1]));
					ref = *(nps[nps.size () - 1]);
					if (befref)
				}
			}
		}
		/*trav (p, given)
		{
			while (p.s.size () > 1)
			{
				int best_cost = *(p.s.begin ());
				p.s.erase (p.s.begin ());
				ans += p.s.size ()*best_cost;
				given[p.f + p.s.size ()].insert (best_cost);
			}
		}*/
		cout << ans << '\n';
	}

	return 0;
}

