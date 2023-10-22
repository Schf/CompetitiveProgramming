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
	string s;
	cin >> s;
	set <ll> bears;
	for (i = 0; i < s.size (); ++i)
		if (s.substr (i, 4) == "bear")
			bears.insert (i);
	ll ans = 0;
	for (i = 0; i < s.size () && bears.lower_bound (i) != bears.end (); ++i)
		ans += s.size () - *bears.lower_bound (i) - 3;
	cout << ans << '\n';

	return 0;
}

