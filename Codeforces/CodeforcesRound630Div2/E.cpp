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

ll fastpow (ll a, ll p)
{
	if (p == 0) return 1;
	ll ans = 1, mult = fastpow (a, p/2);
	if (p&1) ans = a;
	return (((a*mult) % MOD) * mult) % MOD;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, l, r;
	cin >> n >> m >> l >> r;
	if (r == l) cout << 1 << '\n';
	else cout << fastpow ((r-l+2)/2, m*n) + fastpow ((r-l+1)/2, m*n) % MOD << '\n';
	

	return 0;
}


