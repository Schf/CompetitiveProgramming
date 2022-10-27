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
		ll i, j, n, t;
		cin >> n >> t;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		sort (inp.begin (), inp.end ());
		__int128 ub = INFLL, lb = 1, mb = ub/2 + lb/2;
		while (ub - lb > 1)
		{
			__int128 sum = 0;
			trav (a, inp)
				sum += mb/a;
			if (sum < t) lb = mb;
			else ub = mb;
			mb = (ub + lb)/2;
		}
		__int128 sum = 0;
		trav (a, inp)
			sum += mb/a;
		if (sum < t) ++mb;
		cout << (ll) mb << '\n';
	}

	return 0;
}


