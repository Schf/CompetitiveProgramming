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

const ll MOD = 998244353;
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
		ll i, j, n, k;
		cin >> n >> k;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		ll ans = 1, lpos = 0;
		for (i = 0; i < n; ++i)
			if (inp[i] >= n - k + 1)
				break;
		lpos = i;
		vector <ll> sz;
		for (++i; i < n; ++i)
			if (inp[i] >= n - k + 1)
				sz.push_back (i - lpos),
				lpos = i;
		trav (a, sz) ans = ans * a % MOD;
		cout << k*(2*n-k+1)/2 << ' ' << ans << '\n';
	}

	return 0;
}


