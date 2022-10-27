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
	int i, j, n;
	cin >> n;
	vector <vector <int>> graph (n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
		{
			int has; cin >> has;
			if (has) graph[i].push_back (j);
		}
	for (i = 0; i < n; ++i)
	{
		vector <int> viz (n, 0);
		vector <queue <int>> bfs (2);
		int ans = 0;
		bfs[0].push (i);
		for (int pp = 0; !bfs[pp].empty () && !viz[i]; pp ^= 1, ++ans)
		{
			while (!bfs[pp].empty ())
			{
				int cur = bfs[pp].front (); bfs[pp].pop ();
				trav (v, graph[cur])
					if (!viz[v])
						bfs[pp^1].push (v), viz[v] = 1;
			}
		}
		if (viz[i]) cout << ans << '\n';
		else cout << "NO WAY\n";
	}
	

	return 0;
}


