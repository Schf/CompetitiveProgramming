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
		ll i, j, n, k;
		cin >> n >> k;
		vector <ll> wt (n), viz (n, 0);
		trav (a, wt) cin >> a;
		sort (wt.begin (), wt.end ());
		ll ans = 0;
		for (i = 0, j = n - 1; i < j; ++i, --j)
		{
			for (; i < j && k < wt[i] + wt[j]; --j);
			if (i < j) viz[i] = viz[j] = 1, ++ans;
		}
		trav (v, viz) if (!v) ++ans;
		cout << ans << '\n';
	}

	return 0;
}


