#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll b, ll m)
{
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}

ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    return (inv * a) % m;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

ll mod_pot (ll num, ll expo)
{
	if (expo == 0) return 1;
	else if (expo == 1) return num % MOD;
	ll ans = 1, mult = mod_pot (num, expo/2);
	if (expo & 1) ans = ans*num;
	ans = (ans*mult % MOD)*mult % MOD;
	return ans;
}

ll mod_c (ll n, ll k)
{
	if (n - k < k) k = n - k;
	ll ans = 1;
	for (; k > 0; --k, --n)
		ans = ans * modDivide (n, k, MOD) % MOD;
	return ans;
}

inline void mod_add (ll & a, ll b)
{
	a += b;
	while (a >= MOD) a -= MOD;
	while (a < 0) a += MOD;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1;// cin >> tc;
	while (tc--)
	{
		ll i, j, n, a, b, den_a = 1, den_b = 1;
		cin >> n >> a >> b;
		ll ans = mod_pot (2, n);
		//ll f = mod_fat (a, a + 1 - MAXN/2, MAXN/2);
		ll f = 1;
		for (i = 2; i <= a; ++i)
			f = f * i % MOD;
		mod_add (ans, -1);
		mod_add (ans, -mod_c (n, a));
		mod_add (ans, -mod_c (n, b));
		cout << ans << '\n';
	}

	return 0;
}


