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
	ll i, j, n, q;
	cin >> n;
	while (cin >> n >> q)
	{
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		if (n == 1)
		{
			cout << inp[0] << '\n';
			continue;
		}
		if (n == 2)
		{
			cout << max (inp[0], inp[1]) << '\n';
			continue;
		}
		vector <vector <ll>> dp (n, vector <ll> (4));
		// dp[i][0] i ausente, quer negativo
		// dp[i][1] i ausente, quer positivo
		// dp[i][2] i positivo, quer negativo
		// dp[i][3] i negativo, quer positivo
		dp[0][2] = inp[0];
		dp[1][0] = dp[0][2];
		dp[1][2] = inp[1];
		dp[1][3] = inp[0] - inp[1];
		for (i = 2; i < n; ++i)
		{
			dp[i][0] = max (dp[i - 1][0], dp[i - 1][2]);
			dp[i][1] = max (dp[i - 1][1], dp[i - 1][3]);
			dp[i][2] = max (dp[i - 1][1], dp[i - 1][3]) + inp[i];
			dp[i][3] = max (dp[i - 1][0], dp[i - 1][2]) - inp[i];
		}
		//trav (v, dp) cout << v[0] << ' ';
		//cout << '\n';
		//trav (v, dp) cout << v[1] << ' ';
		//cout << '\n';
		//trav (v, dp) cout << v[2] << ' ';
		//cout << '\n';
		//trav (v, dp) cout << v[3] << ' ';
		//cout << '\n';
		cout << max ({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
		cout << '\n';
	}

	return 0;
}

