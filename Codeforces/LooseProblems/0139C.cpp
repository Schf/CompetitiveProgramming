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
	ll i, j, n, m, x, y;
	cin >> n >> m >> x >> y;
	vector <ll> cols (m + 1, 0), pref (m + 1, 0);
	// 1 index pq tem prefix sum
	for (i = 0; i < n; ++i)
		for (j = 1; j <= m; ++j)
		{
			char in;
			cin >> in;
			cols[j] += (in == '#');
			pref[j] = cols[j];
		}
	for (i = 1; i <= m; ++i)
		pref[i] += pref[i - 1];
	vector <pair <ll, ll>> dp (m + 1, {0, INF});
	for (i = 0; i < x; ++i)
		dp[i + 1].f = cols[i] + dp[i].f;
	dp[i].s = n*x - (dp[i].f - dp[0].f) + dp[-1].f;
	for (; i < m; ++i)
	{
		dp[i + 1].f = cols[i] + dp[i].f;
		for (j = x; j < y && i + 1 - j >= 0; ++j)
			dp[i + 1].s = min (dp[i + 1].s, n*j - (dp[i + 1].f - dp[i + 1 - j].f));
	}
	trav (a, cols) cout << a << ' ';
	cout << '\n';
	trav (p, dp) cout << p.f << ' ';
	cout << '\n';
	trav (p, dp) cout << p.s << ' ';
	cout << '\n';
	cout << min (dp[m].f, dp[m].s) << '\n';

	return 0;
}

