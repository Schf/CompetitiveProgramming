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
	ll i, j, n, b, d;
	cin >> n >> b >> d;
	ll ans = 0, cd = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> j;
		if (j > b) continue;
		cd += j;
		if (cd > d) cd = 0, ++ans;
	}
	cout << ans << '\n';

	return 0;
}

