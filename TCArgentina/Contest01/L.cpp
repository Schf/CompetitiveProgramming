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
	ll i, j, n, ans = 0;
	cin >> n;
	vector <vector <pair <ll, ll>>> inp (n, vector <pair <ll, ll>> (n)), dp;
	trav (v, inp)
		trav (a, v)
			cin >> a.f;
	dp = inp;
	for (i = n - 1; i >= 0; --i)
		for (j = n - 1; j >= 0; --j)
			if (i == n - 1 && j == n -1)
				dp[i][j].s = 3;
			else if (i == n - 1)
				dp[i][j].f += dp[i][j + 1].f,
				dp[i][j].s = 0;
			else if (j == n - 1 || dp[i + 1][j].f > dp[i][j + 1].f)
				dp[i][j].f += dp[i + 1][j].f,
				dp[i][j].s = 1;
			else
				dp[i][j].f += dp[i][j + 1].f,
				dp[i][j].s = 0;
	ans = dp[0][0].f;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			dp[i][j].f = inp[i][j].f;
	for (i = j = 0; i < n && j < n;)
	{
		ll aux = dp[i][j].s;
		dp[i][j].f = 0;
		i += aux;
		j += 1 - aux;
	}
	for (i = n - 1; i >= 0; --i)
		for (j = n - 1; j >= 0; --j)
			if (i == n - 1 && j == n -1)
				dp[i][j].s = 3;
			else if (i == n - 1)
				dp[i][j].f += dp[i][j + 1].f,
				dp[i][j].s = 0;
			else if (j == n - 1 || dp[i + 1][j].f > dp[i][j + 1].f)
				dp[i][j].f += dp[i + 1][j].f,
				dp[i][j].s = 1;
			else
				dp[i][j].f += dp[i][j + 1].f,
				dp[i][j].s = 0;
	ans += dp[0][0].f;
	cout << ans << '\n';

	return 0;
}

