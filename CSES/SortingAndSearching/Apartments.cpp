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
		ll i, j, n, m, k;
		cin >> n >> m >> k;
		vector <ll> mr (n), ap (m);
		trav (a, mr) cin >> a;
		trav (a, ap) cin >> a;
		sort (mr.begin (), mr.end ());
		sort (ap.begin (), ap.end ());
		ll ans = 0;
		for (i = j = 0; i < mr.size () && j < ap.size ();)
		{
			if (abs (mr[i] - ap[j]) <= k) ++i, ++j, ++ans;
			else if (mr[i] + k < ap[j]) ++i;
			else ++j;
		}
		cout << ans << '\n';
	}

	return 0;
}


