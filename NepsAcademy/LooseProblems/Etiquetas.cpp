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
	int i, j, n, k, c;
	cin >> n >> k >> c;
	vector <ll> given (n), pref (n + 1, 0);
	vector <vector <ll>> dp (k + 1, vector <ll> (n + 1, 0));
	ll sum = 0;
	trav (a, given) cin >> a;
	trav (a, given) sum += a;
	pref[1] = given[0];
	for (i = 2; i <= n; ++i) pref[i] = given[i - 1] + pref[i - 1];
	for (i = n; i >= c; --i) pref[i] -= pref[i - c];
	dp[1][c] = pref[c];
	for (i = 1; i <= k; ++i)
	{
		dp[i][i*c] = dp[i-1][(i-1)*c] + pref[i*c];
		for (j = i*c + 1; j <= n; ++j)
			dp[i][j] = min (dp[i][j - 1], dp[i - 1][j - c] + pref[j]);
	}
	cout << sum - dp[k][n] << '\n';

	return 0;
}


