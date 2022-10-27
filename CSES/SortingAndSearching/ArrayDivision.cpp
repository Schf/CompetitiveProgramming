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
		ll i, j, n, k, tsum = 0, mx = 0;
		cin >> n >> k;
		vector <ll> inp (n);
		trav (a, inp) cin >> a, tsum += a, mx = max (mx, a);
		ll ub = tsum, lb = mx, mb = (ub + lb)/2;
		while (ub - lb > 1)
		{
			ll cur = 0, cc = 1;
			for (i = 0; i < n; ++i)
				if (cur + inp[i] > mb) cur = inp[i], ++cc;
				else cur += inp[i];
			if (cc > k) lb = mb;
			else ub = mb;
			mb = (ub + lb)/2; 
		}
		ll cur = 0, cc = 1;
		for (i = 0; i < n; ++i)
			if (cur + inp[i] > mb) cur = inp[i], ++cc;
			else cur += inp[i];
		if (cc > k) ++mb;
		cout << mb << '\n';
	}

	return 0;
}

