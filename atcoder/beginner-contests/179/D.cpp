#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 998244353;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

ll rsq (vector <ll> & tree, ll l, ll r)
{
	ll i, j, n = tree.size ()/2;
	l = max (0LL, l);
	r = max (0LL, r);
	ll ret = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1) ret += tree[l++], ret %= MOD;
		if (r&1) ret += tree[--r], ret %= MOD;
	}
	return ret;
}

void upd (vector <ll> & tree, ll p, ll v)
{
	ll i, n = tree.size ()/2;
	tree[n + p] = v;
	for (i = (n + p) >> 1; i > 0; i >>= 1)
		tree[i] = tree[i<<1] + tree[i<<1|1],
		tree[i] %= MOD;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, k;
	cin >> n >> k;
	vector <ll> dp (n), tree (2*n, 0);
	vector <pair <ll, ll>> qr (k);
	trav (p, qr) cin >> p.f >> p.s;
	sort (qr.begin (), qr.end ());
	dp[0] = 1;
	tree[n] = 1;
	for (i = n; i > 0; i >>= 1)
		tree[i] = 1;
	for (i = 1; i < n; ++i)
	{
		for (j = 0; j < k; ++j)
			dp[i] += rsq (tree, i - qr[j].s, i - qr[j].f + 1),
			dp[i] %= MOD;
		upd (tree, i, dp[i]);
	}
	//trav (a, dp) cout << a << '\n';
	cout << dp[n - 1] << '\n';

	return 0;
}

