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
	vector <pair <ll, ll>> inp (n);
	trav (p, inp) cin >> p.f >> p.s;
	if (n < 3)
	{
		cout << n << '\n';
		return 0;
	}
	vector <vector <ll>> dp (n, vector <ll> (3));
	dp[0][0] = 0;
	dp[0][1] = 1;
	if (inp[0].f + inp[0].s < inp[1].f) dp[0][2] = 1;
	else dp[0][2] = -INF;
	for (i = 1; i < n - 1; ++i)
	{
		dp[i][0] = max ({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
		if (inp[i - 1].f < inp[i].f - inp[i].s)
			dp[i][1] = max (dp[i - 1][0], dp[i - 1][1]) + 1;
		else dp[i][1] = -INF;
		if (inp[i - 1].f + inp[i - 1].s < inp[i].f - inp[i].s)
			dp[i][1] = max (dp[i][1], dp[i - 1][2] + 1);
		if (inp[i].f + inp[i].s < inp[i + 1].f)
			dp[i][2] = dp[i][0] + 1;
		else dp[i][2] = -INF;
	}
	/*trav (v, dp)
	{
		trav (a, v) if (a < 0) cout << "- "; else cout << a << ' ';
		cout << "| " << max ({v[0], v[1], v[2]}) << '\n';
	}*/
	cout << max ({dp[n - 2][0], dp[n - 2][1], dp[n - 2][2]}) + 1 << '\n';

	return 0;
}

