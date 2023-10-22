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
		int dp[n][n];
		char grid[n][n];
		memset (dp, 0, sizeof dp);
		memset (grid, 0, sizeof grid);
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				while (grid[i][j] != '.' && grid[i][j] != '*')
					cin >> grid[i][j];
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (grid[i][j] == '*');
				else if (!i && !j) dp[i][j] = 1;
				else if (!i) dp[i][j] = dp[i][j - 1];
				else if (!j) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = (((grid[i - 1][j] == '.') ? (dp[i - 1][j]) : (0)) +
						((grid[i][j - 1] == '.') ? (dp[i][j - 1]) : (0))) % MOD;
		cout << dp[n - 1][n - 1] << '\n';
	}

	return 0;
}


