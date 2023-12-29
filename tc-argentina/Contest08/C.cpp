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
	ll i, j, n, m;
	cin >> n >> m;
	vector <ll> t, x, cost;
	t = x = cost = vector <ll> (n);
	for (i = 0; i < n; ++i)
		cin >> j >> t[i] >> x[i] >> cost[i], t[i] -= j;
	ll ans = 0;
	for (i = 0; i < n; ++i)
	{
		if (t[i] >= m) ans += cost[i];
		else if (t[i] > 0)
			ans += min ({m*x[i] + cost[i],
					((m - 1)/t[i] + 1)*cost[i],
					(m - 1)/t[i]*cost[i] + ((m - 1)%t[i] + 1 + t[i])*x[i]});
		else
			ans += m*x[i] + cost[i];
	}
	cout << ans << '\n';

	return 0;
}

