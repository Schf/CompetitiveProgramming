#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <pair <ll, ll>> inp (n, {0, -1});
		map <ll, ll> check;
		trav (p, inp) cin >> p.f, check[p.f] = -1;
		check[inp[0].f] = 0;
		for (i = 1; i < n; ++i)
			inp[i].s = max (check[inp[i].f], inp[i - 1].s), check[inp[i].f] = i;
		ll ans = 0;
		for (i = 0; i < n; ++i)
			ans = max (ans, i - inp[i].s);
		cout << ans << '\n';
	}

	return 0;
}


