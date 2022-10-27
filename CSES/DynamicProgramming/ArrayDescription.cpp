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
		int i, j, n, m;
		cin >> n >> m;
		vector <int> g (n), mn (n), mx (n);
		trav (a, g) cin >> a;
		vector <vector <ll>> dp, tab;
		dp = tab = vector <vector <ll>> (n, vector <ll> (m + 1, 0));
		for (int i = 0, j = 1e4, l = 0; i < n; ++i)
			if (g[i]) l = i, j = 0, mx[i] = mn[i] = g[i];
			else ++j, mn[i] = g[l] - j, mx[i] = g[l] + j;
		for (int i = n - 1, j = 1e4, l = 0; i >= 0; --i)
			if (g[i]) l = i, j = 0, mx[i] = mn[i] = g[i];
			else ++j, mn[i] = max (mn[i], g[l] - j),
					mx[i] = min (mx[i], g[l] + j);
		trav (a, mn) a = max (1, a);
		trav (a, mx) a = min (m, a);
		for (j = mn[0]; j <= mx[0]; ++j)
			dp[0][j] = 1;
		for (i = 1; i < n; ++i)
			for (j = mn[i]; j <= mx[i]; ++j)
				for (int k = max (j - 1, 1); k <= min (j + 1, m); ++k)
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
		/*trav (v, dp)
		{
			trav (a, v)
				cout << a << ' ';
			cout << '\n';
		}*/
		ll ans = 0;
		trav (a, dp[n - 1]) ans = (ans + a) % MOD;
		cout << ans << '\n';
	}

	return 0;
}


