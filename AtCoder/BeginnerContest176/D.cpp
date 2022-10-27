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

#define fits(i, j, n, m) \
	(0 <= (i) && (i) < (n) && 0 <= (j) && (j) < (m))

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, cn, cm, dn, dm;
	cin >> n >> m >> cn >> cm >> dn >> dm;
	--cn, --cm, --dn, --dm;
	vector <string> inp (n);
	vector <vector <ll>> cost (n, vector <ll> (m, INF));
	trav (s, inp) cin >> s;
	set <pair <ll, ll>> bfs;
	cost[cn][cm] = 0, bfs.insert ({cn, cm});
	vector <pair <ll, ll>> jump, adj = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
	for (i = -2; i < 3; ++i)
		for (j = -2; j < 3; ++j)
			if ((i || j) && find (adj.begin (), adj.end (),
					make_pair (i, j)) == adj.end ())
				jump.push_back ({i, j});
	while (!bfs.empty ())
	{
		auto c = *bfs.begin ();
		bfs.erase (bfs.begin ());
		bool search = false;
		for (auto p : adj)
		{
			i = c.f + p.f;
			j = c.s + p.s;
			if (fits (i, j, n, m) && inp[i][j] == '.' &&
					cost[i][j] > cost[c.f][c.s])
				cost[i][j] = cost[c.f][c.s], bfs.insert ({i, j});
			if (fits (i, j, n, m) && inp[i][j] == '#') search = true;
		}
		if (search)
			for (auto p : jump)
			{
				i = c.f + p.f;
				j = c.s + p.s;
				if (fits (i, j, n, m) && inp[i][j] == '.' &&
						cost[i][j] > cost[c.f][c.s] + 1)
					cost[i][j] = cost[c.f][c.s] + 1, bfs.insert ({i, j});
			}
	}
	if (cost[dn][dm] >= INF/2) cout << "-1\n";
	else cout << cost[dn][dm] << '\n';

	return 0;
}

