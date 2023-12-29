#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, x, k, d;
	cin >> x >> k >> d;
	x = abs (x);
	if (d <= x)
		if (x/d <= k)
			k -= x/d,
			x = x%d;
		else x -= k*d, k = 0;
	if (k%2) cout << abs (x - d);
	else cout << abs (x);
	cout << '\n';

	return 0;
}

