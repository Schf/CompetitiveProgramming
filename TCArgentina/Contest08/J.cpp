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
	ll i, j, n;
	string s;
	cin >> n >> s;
	if (n > 26) cout << "-1\n";
	else
	{
		vector <ll> freq ('z' + 1, 0);
		trav (c, s) ++freq[c];
		ll ans = 0;
		trav (a, freq) ans += max ((ll) 0, a - 1);
		cout << ans << '\n';
	}

	return 0;
}

