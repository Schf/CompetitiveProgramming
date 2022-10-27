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
	int tc; cin >> tc;
	while (tc--)
	{
		int i, j, n, m, u, l, k;
		cin >> n >> m >> u >> l >> k; --u;
		vector <vector <pair <int, int>>> graph (n);
		vector <int> dist (n, INF), dp (l + 2, 0);
		for (i = 0; i < m; ++i)
		{
			int a, b, w; cin >> a >> b >> w; --a, --b;
			graph[a].push_back ({b, w});
			graph[b].push_back ({a, w});
		}
		queue <int> bfs;
		bfs.push (u);
		dist[u] = 0;
		while (!bfs.empty ())
		{
			int cur = bfs.front (); bfs.pop ();
			trav (v, graph[cur])
			{
				dp[dist[cur] + 1] = max (dp[dist[cur] + 1], v.s);
				if (dist[v.f] >= dist[cur] + 1 && dist[cur] + 1 <= l)
				{
					dist[v.f] = dist[cur] + 1;
					dp[dist[v.f]] = max (dp[dist[v.f]], v.s);
					bfs.push (v.f);
				}
			}
		}
		int ans = 0;
		for (i = 0; i <= k; ++i)
			ans = max (ans, dp[i]);
		cout << ans << '\n';
	}

	return 0;
}


