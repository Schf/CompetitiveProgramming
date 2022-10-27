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

ll log2 (ll a)
{
	ll ans = 0;
	while (a >>= 1) ++ans;
	return ans;
}

ll query (ll a, ll b, ll n, ll l, ll r)
{
	if (r - l <= 1) return 1;
	if (a > b) swap (a, b);
	ll m = (l + r) / 2;
	if (a <= m && b > m) return log2 (r - l + 1);
	else if (b <= m) r = m;
	else l = m + 1;
	return query (a, b, n, l, r);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, q;
	cin >> n >> q;
	vector <ll> inp (n);
	for (i = 0; i < n; ++i)
		cin >> j, --j,
		inp[j] = i;
	for (ll qq = 0; qq < q; ++qq)
	{
		ll t, x, y;
		cin >> t >> x >> y;
		--x, --y;
		if (t == 1) swap (inp[x], inp[y]);
		else cout << query (inp[x], inp[y], n, 0, n - 1) << '\n';
	}

	return 0;
}


