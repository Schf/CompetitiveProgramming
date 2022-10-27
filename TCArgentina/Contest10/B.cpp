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

bool is_pal (string & s, ll l, ll r)
{
	ll i, j;
	for (i = 0; l + i < r - i; ++i)
		if (s[l + i] != s[r - i]) return false;
	return true;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string s;
	cin >> s;
	ll ans = 0;
	n = s.size ();
	for (i = 0; i < n; ++i)
		for (j = i; j < n; ++j)
			if (!is_pal (s, i, j))
				ans = max (ans, j - i + 1);
	cout << ans << '\n';

	return 0;
}

