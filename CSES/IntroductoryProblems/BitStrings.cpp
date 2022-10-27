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

ll fast_pow (ll num, ll ex)
{
	if (ex == 1) return num;
	if (ex == 0) return 1;
	ll ans = 1, mul = fast_pow (num, ex/2);
	if (ex&1) ans = num;
	return ans * mul % MOD * mul % MOD;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i = 0, j, n;
		cin >> n;
		cout << fast_pow (2, n) << '\n';
	}

	return 0;
}


