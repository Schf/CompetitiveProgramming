#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	vector <vector <ll>> dp (n + 1, vector <ll> (3, INF));
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> j;
		dp[i + 1][0] = min ({dp[i][0], dp[i][1], dp[i][2]}) + 1;
		if (j%2) dp[i + 1][1] = min (dp[i][0], dp[i][2]);
		if (j/2) dp[i + 1][2] = min (dp[i][0], dp[i][1]);
	}
	cout << min ({dp[n][0], dp[n][1], dp[n][2]}) << '\n';

	return 0;
}

