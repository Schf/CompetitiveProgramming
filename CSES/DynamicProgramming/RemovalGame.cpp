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
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		ll dp[n][n];
		memset (dp, 0, sizeof dp);
		for (i = 0; i < n; ++i)
			cin >> dp[i][i];
		for (i = 1; i < n; ++i)
			dp[i - 1][i] = max (dp[i - 1][i - 1], dp[i][i]);
		for (i = n - 3; i >= 0; --i)
			for (j = i + 2; j < n; ++j)
				dp[i][j] = max (dp[i][i] + min (dp[i + 2][j], dp[i + 1][j - 1]),
							min (dp[i + 1][j - 1], dp[i][j - 2]) + dp[j][j]);
		cout << dp[0][n - 1] << '\n';
	}

	return 0;
}

