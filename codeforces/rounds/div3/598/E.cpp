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
	for (i = 0; i < n; ++i)
		cin >> inp[i].f, inp[i].s = i;
	sort (inp.begin (), inp.end ());
	vector <ll> dp (n + 1, INF), ord (n + 1, INF), ans (n, INF);
	dp[0] = 0;
	for (i = 0; i + 2 < n; ++i)
	{
		if (dp[i + 3] > dp[i] + inp[i + 2].f - inp[i].f)
			ord[i + 3] = 3, dp[i + 3] = dp[i] + inp[i + 2].f - inp[i].f;
		if (i + 3 < n && dp[i + 4] > dp[i] + inp[i + 3].f - inp[i].f)
			ord[i + 4] = 4, dp[i + 4] = dp[i] + inp[i + 3].f - inp[i].f;
		if (i + 4 < n && dp[i + 5] > dp[i] + inp[i + 4].f - inp[i].f)
			ord[i + 5] = 5, dp[i + 5] = dp[i] + inp[i + 4].f - inp[i].f;
	}
	for (i = n, j = 1; i > 0; i -= ord[i], ++j)
		if (ans[inp[i - 1].s] >= INF)
			for (ll k = 1; k <= ord[i]; ++k)
				ans[inp[i - k].s] = j;
	cout << dp[n] << ' ' << j - 1 << '\n';
	trav (a, ans) cout << a << ' ';
	cout << '\n';

	return 0;
}

