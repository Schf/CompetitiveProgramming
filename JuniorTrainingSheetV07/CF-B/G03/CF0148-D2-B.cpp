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
	ll i, j, n, vp, vd, t, f, c, ans = 0;
	cin >> vp >> vd >> t >> f >> c;
	if (vp >= vd)
	{
		cout << "0\n";
		return 0;
	}
	double tt, dt;
	tt = t;
	dt = tt*vp;
	while (1)
	{
		tt += dt/(vd - vp);
		dt = tt*vp;
		if (dt < c) ++ans;
		else break;
		tt += dt/vd;
		tt += f;
		dt = tt*vp;
	}
	cout << ans << '\n';


	return 0;
}

