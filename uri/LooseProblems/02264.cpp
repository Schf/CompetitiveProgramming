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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, m, t;
		cin >> t >> m >> n;
		vector <vector <ll>> dp (t, vector <ll> (n - m + 1, 0));
		for (j = 0; j + m <= n; ++j) dp[0][j] = 1;
		for (i = 1; i < t; ++i)
		{
			dp[i][0] = dp[i - 1][1];
			for (j = 1; j + m < n; ++j)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			dp[i][n - m] = dp[i - 1][n - m - 1];
		}
		ll ans = 0;
		for (j = 0; j + m <= n; ++j) ans = (ans + dp[t - 1][j]) % MOD;
		for (j = 0; j + m <= n; ++j)
		{
			for (i = 0; i < t; ++i)
				printf (" % 5lld", dp[i][j]);
			printf ("\n");
		}
		cout << '\n';
		cout << ans << '\n';
	}

	return 0;
}


