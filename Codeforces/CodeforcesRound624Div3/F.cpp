#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n;
		cin >> n;
		vector <pair <ll, ll>> space (n), veloc (n);
		// .f = value, .s = index of point in the other vector
		for (i = 0; i < n; ++i) cin >> space[i].f, veloc[i].s = i;
		for (i = 0; i < n; ++i) cin >> veloc[i].f, space[i].s = i;
		
		sort (space.begin (), space.end ());
		for (i = 0; i < n; ++i) veloc[space[i].s].s = i;
		sort (veloc.begin (), veloc.end ());
		for (i = 0; i < n; ++i) space[veloc[i].s].s = i;
		
		ll ans = 0;
		for(i = 0; i < n; ++i)
			ans += space[i].f * i,
			ans -= space[i].f * (n - i - 1);
		
		for (i = 0; i < n; ++i)
			ans -= space[veloc[i].s].f * (veloc[i].s - i);

		cout << ans << '\n';
	}

	return 0;
}


