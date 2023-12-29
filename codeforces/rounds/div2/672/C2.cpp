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

void upd (vector <vector <ll>> & dp, ll p, ll v)
{
	ll i, j, n = dp.size () / 2;
	i = p + n;
	dp[i][1] = dp[i][3] = v;
	for (i >>= 1; i > 0; i >>= 1)
		dp[i][0] = min (dp[i<<1][0] + dp[i<<1|1][0], dp[i<<1][1] - dp[i<<1|1][3]),
		dp[i][1] = min (dp[i<<1][0] + dp[i<<1|1][1], dp[i<<1][1] - dp[i<<1|1][2]),
		dp[i][2] = max (dp[i<<1][2] + dp[i<<1|1][2], dp[i<<1][3] - dp[i<<1|1][1]),
		dp[i][3] = max (dp[i<<1][2] + dp[i<<1|1][3], dp[i<<1][3] - dp[i<<1|1][0]);
}

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
		for (i = 0; n > 1; ++i, n >>= 1);
		for (; i >= 0; --i, n <<= 1);
		vector <vector <ll>> dp (2*n, vector <ll> (4, 0));
		for (i = 0; i < inp.size (); ++i)
			upd (dp, i, inp[i]);
		cout << max ({-dp[1][0], -dp[1][1], dp[1][2], dp[1][3]}) << '\n';
		for (ll qq = 0; qq < q; ++qq)
		{
			ll l, r, vl, vr;
			cin >> l >> r;
			vl = dp[--l + n][3];
			vr = dp[--r + n][3];
			upd (dp, l, vr);
			upd (dp, r, vl);
			cout << max ({-dp[1][0], -dp[1][1], dp[1][2], dp[1][3]}) << '\n';
		}
	}

	return 0;
}

