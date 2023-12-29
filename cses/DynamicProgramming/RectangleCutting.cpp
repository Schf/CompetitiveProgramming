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
		int i, j, n, a, b;
		cin >> a >> b;
		if (a < b) swap (a, b);
		int dp[a + 1][b + 1];
		for (i = 0; i <= a; ++i)
			for (j = 0; j <= b; ++j)
				dp[i][j] = i*(j <= i ? j : 0);
		for (i = 1; i <= a; ++i)
			for (j = 1; j <= i && j <= b; ++j)
				dp[i][j] = i/j + dp[max (i%j, j)][min (i%j, j)];
		trav (v, dp)
		{
			trav (a, v) cout << a << ' ';
			cout << '\n';
		}
		cout << dp[a][b] - 1 << '\n';
	}

	return 0;
}

