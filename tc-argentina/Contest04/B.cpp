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
	cin >> n;
	map <ll, vector <ll>> mp;
	for (i = 0; i < n; ++i)
	{
		ll a, x;
		cin >> a >> x;
		mp[a].push_back (x);
	}
	cin >> m;
	for (i = 0; i < m; ++i)
	{
		ll b, y;
		cin >> b >> y;
		mp[b].push_back (y);
	}

	ll ans = 0;
	trav (v, mp)
		ans += *max_element (v.s.begin (), v.s.end ());
	cout << ans << '\n';

	return 0;
}

