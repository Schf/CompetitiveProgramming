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
	ll i, j, n;
	ll p, q, l, r;
	cin >> p >> q >> l >> r;
	vector <pair <ll, ll>> Z (p), X (q);
	trav (p, Z) cin >> p.f >> p.s;
	trav (p, X) cin >> p.f >> p.s;
	ll ans = 0;
	for (ll t = l; t <= r; ++t)
	{
		bool can = false;
		trav (z, Z)
		{
			trav (x, X)
				if ((x.f + t <= z.f && z.f <= x.s + t) || (x.f + t <= z.s && z.s <= x.s + t) ||
					(z.f <= x.f + t && x.f + t <= z.s) || (z.f <= x.s + t && x.s + t <= z.s))
				{
					can = true;
					break;
				}
			if (can)
				break;
		}
		if (can)
			++ans;
	}
	cout << ans << '\n';

	return 0;
}

