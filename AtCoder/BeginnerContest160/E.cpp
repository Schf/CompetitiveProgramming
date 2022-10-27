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
	ll i, j, n, x, y, r, g, c;
	cin >> x >> y >> r >> g >> c;
	vector <ll> R (r), G (g), eaten (x + y + c);
	trav (a, R) cin >> a;
	trav (a, G) cin >> a;
	sort (R.rbegin (), R.rend ());
	sort (G.rbegin (), G.rend ());
	for (i = j = 0; i < x; ++i, ++j) eaten[j] = R[i];
	for (i = 0; i < y; ++i, ++j) eaten[j] = G[i];
	for (; j < eaten.size (); ++j) cin >> eaten[j];
	sort (eaten.rbegin (), eaten.rend ());
	ll ans = 0;
	for (i = 0; i < x + y; ++i) ans += eaten[i];
	cout << ans << '\n';

	return 0;
}


