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
	ll i, j, n, q;
	cin >> n >> q;
	vector <pair <ll, ll>> alg (n, {1, n});
	for (ll qq = 0; qq < q; ++qq)
	{
		ll m, l, r, t;
		cin >> m >> l >> r >> t;
		--l, --r;
		for (i = l; i <= r; ++i)
			if (m == 1) alg[i].f = max (alg[i].f, t);
			else alg[i].s = min (alg[i].s, t);
	}
	trav (p, alg)
		if (p.f > p.s)
		{
			cout << -1 << '\n';
			return 0;
		}
	sort (alg.begin (), alg.end (), [&] (auto & a, auto & b)
	{
		if (a.s - a.f == b.s - b.f) return a < b;
		return a.s - a.f < b.s - b.f;
	});
	vector <ll> dp (n, 0);
	ll ans = 0, sum = 0;
	for (i = 0; i < alg.size (); ++i)
		for (j = alg[i].f; j <= alg[i].s; ++j)
			++dp[j - 1];
	sort (dp.begin (), dp.end ());
	for (i = 0; i < n; ++i)
		if (dp[i] <= i) ++sum;
	vector <ll> cnt (n - sum, 0);
	for (i = 0; i < n; ++i)
		++cnt[i%cnt.size ()];

	trav (a, cnt) ans += a*a;
	cout << ans << '\n';

	return 0;
}

