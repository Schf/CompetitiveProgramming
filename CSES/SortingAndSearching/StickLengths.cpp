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
		ll i, j, n, sum = 0;
		cin >> n;
		vector <ll> inp (n), f (n);
		trav (a, inp) cin >> a, sum += a;
		sort (inp.begin (), inp.end ());
		f[0] = inp[0];
		for (i = 1; i < n; ++i) f[i] = inp[i] + f[i - 1];
		for (i = 0; i < n; ++i) f[i] = sum - 2*f[i];
		ll ans = INFLL;
		for (i = 0; i < n; ++i)
			ans = min (ans, f[i] + (2*(i + 1) - n)*inp[i]);
		for (i = max (inp[0], sum/n - 100); i <= min (inp.back (), sum/n + 100); ++i)
		{
			ll ub = n - 1, lb = 0, mb = ub / 2;
			while (ub - lb > 1)
			{
				if (inp[mb] <= i) lb = mb;
				else ub = mb;
				mb = (ub + lb) / 2;
			}
			if (inp[mb + 1] <= i) ++mb;
			ans = min (ans, f[mb] + (2*(mb + 1) - n)*i);
		}
		cout << ans << '\n';
	}

	return 0;
}


