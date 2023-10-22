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
		ll i, j, n, ans = 0;
		cin >> n;
		vector <ll> t (n);
		for (i = 0; i < n; ++i)
		{
			cin >> t[i] >> j;
			ans += j;
		}
		sort (t.begin (), t.end ());
		ans -= t[0];
		for (i = 1; i < n; ++i) t[i] += t[i - 1], ans -= t[i];
		cout << ans << '\n';
	}

	return 0;
}


