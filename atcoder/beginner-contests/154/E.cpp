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
	int i, j, n, k;
	string s;
	cin >> s >> k;
	ll dp[s.size () + 1][4][2];
	memset (dp, 0, sizeof dp);
	dp[1][1][1] = 1;
	for (i = 2; i < s.size () + 1; ++i)
	{
		printf ("<%6lld,%6lld> ", dp[i - 1][1][1], dp[i - 1][1][0]);
		dp[i][1][1] = 1;
		dp[i][1][0] = 9*dp[i - 1][1][1] + dp[i - 1][1][0];
		for (j = 2; j < 4; ++j)
		{
			printf ("<%6lld,%6lld> ", dp[i - 1][j][1], dp[i - 1][j][0]);
			dp[i][j][0] = 9*dp[i - 1][j][1] + dp[i - 1][j][0];
			dp[i][j][1] = 9*dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
		}
		printf ("\n");
	}
	printf ("-----------------------------\n");
	for (i = 1; i < s.size () + 1; ++i)
	{
		for (j = 1; j < 4; ++j)
			printf ("<%6lld,%6lld> ", dp[i][j][0], dp[i][j][1]);
		printf ("\n");
	}
	ll ans = 0;
	for (i = 1; i < s.size () + 1; ++i)
		ans += max (dp[i][k][1]*(s[i - 1] - '1'), 0LL);
	ans += dp[s.size ()][k][0] + 1;
	cout << ans << '\n';

	return 0;
}


