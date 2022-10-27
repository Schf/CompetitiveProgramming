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

vector <ll> dp, b;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; cin >> tc;
	while (tc--)
	{
		ll i, j, n, t;
		cin >> n >> t;
		b.clear ();
		dp.clear ();
		dp.resize (3601, INF);
		set <int> inp;
		for (i = 0; i < n; ++i)
		{
			cin >> j;
			inp.insert (j);
		}
		trav (a, inp) b.push_back (a);
		n = b.size ();
		
		queue <pair <int, int>> bfs;
		bfs.push ({0, 0});
		
		while (bfs.size ())
		{
			pair <int, int> cur = bfs.front ();
			bfs.pop ();
			dp[cur.f] = cur.s++;
			for (i = 0; i < n; ++i)
				if (dp[min (3600LL, max (0LL, cur.f + b[i]))] > cur.s)
					dp[min (3600LL, max (0LL, cur.f + b[i]))] = cur.s,
					bfs.push ({min (3600LL, max (0LL, cur.f + b[i])), cur.s});
		}
		
		//for (i = 0; i < 30; ++i)
		//	if (dp[i] < INF) cout << dp[i] << ' ';
		//	else cout << ". ";
		//cout << '\n';
		
		ll extra = 0;
		for (i = t; i <= 3600; ++i, ++extra)
			if (dp[i] != INF)
			{
				dp[t] = dp[i];
				break;
			}
		cout << dp[t] << ' ' << extra << '\n';
	}

	return 0;
}


