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
	ll i, j, n, la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta >> lb >> rb >> tb;
	if (ta == tb)
	{
		cout << min (ra, rb) - max (la, lb) + 1 << '\n';
		return 0;
	}
	if (tb % ta == 0)
		swap (la, lb), swap (ra, rb), swap (ta, tb);
	if (ta % tb == 0)
	{
		ll ans = min ((ra - la) + la%tb, rb) - max (la%tb, lb) + 1;
		ans = max (ans, min ((ra - la) + la%tb, rb + tb) - max (la%tb, lb + tb) + 1);
		cout << ans << '\n';
		return 0;
	}
	
	cout << min (ra - la, rb - lb) + 1 << '\n';

	return 0;
}

