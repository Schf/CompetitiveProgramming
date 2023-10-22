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
		int i, j, n, m;
		string a, b;
		cin >> a >> b;
		if (a.size () < b.size ()) swap (a, b);
		n = a.size ();
		m = b.size ();
		vector <vector <int>> dp (n + 1, vector <int> (m + 1, 0));
		for (i = 0; i <= n; ++i) dp[i][0] = i;
		for (j = 1; j <= m; ++j) dp[0][j] = j;
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= m; ++j)
				if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = 1 + min (dp[i - 1][j],
						min (dp[i][j - 1], dp[i - 1][j - 1]));
		cout << dp[n][m] << '\n';
	}

	return 0;
}


