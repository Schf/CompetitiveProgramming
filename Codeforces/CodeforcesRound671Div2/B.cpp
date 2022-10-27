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
	ll i, j, n;
	cin >> n;
	while (cin >> n)
	{
		ll ans = 0;
		for (i = 2; (j = (i-1)*(i)/2) <= n; i <<= 1)
			//cout << j << ' ',
			++ans, n -= j;
		//cout << j << ' ';
		cout << ans << '\n';
	}

	return 0;
}

