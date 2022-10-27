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
		int i, j, n, c;
		cin >> n >> c;
		vector <pair <int, int>> given (n - 1), dp (n);
		trav (a, given) cin >> a.f;
		trav (a, given) cin >> a.s;
		dp[0] = {0, c};
		for (i = 1; i <= n; ++i)
			dp[i].f = given[i - 1].f + min (dp[i - 1].f, dp[i - 1].s),
			dp[i].s = given[i - 1].s + min (dp[i - 1].f + c, dp[i - 1].s);
		trav (a, dp)
			cout << min (a.f, a.s) << ' ';
		cout << '\n';
	}

	return 0;
}


