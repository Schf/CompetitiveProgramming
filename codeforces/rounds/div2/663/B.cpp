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
	ll i, j, n, m;
	cin >> n;
	while (cin >> n >> m)
	{
		vector <string> inp (n);
		trav (s, inp) cin >> s;
		ll ans = 0;
		for (i = 0; i < n; ++i)
			ans += (inp[i][m - 1] == 'R');
		for (i = 0; i < m; ++i)
			ans += (inp[n - 1][i] == 'D');
		cout << ans << '\n';
	}

	return 0;
}

