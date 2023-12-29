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
	ll i, j, n, m, q;
	cin >> n >> m >> q;
	vector <vector <ll>> inp (n, vector <ll> (m)), dp;
	trav (v, inp)
		trav (a, v)
			cin >> a;
	dp = inp;
	for (i = 0; i < n; ++i)
		for (j = 1; j < m; ++j)
			dp[i][j] = (dp[i][j]&&1)*(1 + dp[i][j - 1]);
	trav (v, dp)
	{
		trav (a, v)
			cout << a << ' ';
		cout << endl;
	}
	cout << endl;
	for (ll qq = 0; qq < q; ++qq)
	{
		ll mode, x, y;
		cin >> mode >> x >> y;
		--x, --y;
		if (mode == 1)
		{
			inp[x][y] = !inp[x][y];
			dp[x][y] = !dp[x][y];
			for (j = 1; j < m; ++j)
				dp[x][j] = (dp[x][j]&&1)*(1 + dp[x][j - 1]);
			trav (v, dp)
			{
				trav (a, v)
					cout << a << ' ';
				cout << endl;
			}
			cout << endl;
		}
		else
		{
			ll w = dp[x][y], h = 1;
			vector <ll> up (y + 1, -1), dw (y + 1, -1);

		}
	}

	return 0;
}

