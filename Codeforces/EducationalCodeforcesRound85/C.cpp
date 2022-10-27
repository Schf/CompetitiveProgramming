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
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <pair <ll, ll>> inp (n);
		trav (p, inp) cin >> p.f >> p.s;
		ll ans = max (0LL, inp[0].f - inp[n - 1].s);
		for (i = 1; i < n; ++i)
			ans += max (0LL, inp[i].f - inp[i - 1].s);
		ll mn = INF;
		trav (p, inp) mn = min (mn, p.f);
		ans += mn;
		cout << ans << '\n';
	}

	return 0;
}

