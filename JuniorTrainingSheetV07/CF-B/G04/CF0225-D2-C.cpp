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
	ll i, j, n, m, x, y;
	cin >> n >> m >> x >> y;
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	vector <ll> wht (m), suf (m + 1);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			wht[j] += (inp[i][j] == '.');
	for (i = m - 1; i >= 0; --i)
		suf[i] = wht[i] + suf[i + 1];
	vector <pair <ll, ll>> dp (m + 1, {INF, INF});
	dp[0].f = dp[0].s = 0;
	for (i = 1; i <= m; ++i)
		for (j = x; j <= y && i - j >= 0; ++j)
			dp[i].f = min (dp[i].f, dp[i - j].s + suf[i - j] - suf[i]),
			dp[i].s = min (dp[i].s, dp[i - j].f + n*j - suf[i - j] + suf[i]);
	//trav (p, dp) cout << p.f << ' ' << p.s << " | ";
	//cout << '\n';
	cout << min (dp[m].f, dp[m].s) << '\n';

	return 0;
}

