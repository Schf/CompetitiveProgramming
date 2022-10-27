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
	ll tc = 1; cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector<pair<ll, pair<ll, ll>>> v(n);
		
		for (i = 0; i < n ; ++i){
			cin >> v[i].f >> v[i].s.f >> v[i].s.s;
		}
		
		sort(v.begin(), v.end());
		ll mx2 = v[0].s.f, mx3 = v[0].s.s, ans = 1;
		
		for (i = 1; i < v.size (); ++i)
			if (mx2 > v[i].s.f || mx3 > v[i].s.s)
				++ans, mx2 = max (mx2, v[i].s.f), mx3 = max (mx3, v[i].s.s);
		
		cout << ans << '\n';
	}

	return 0;
}


