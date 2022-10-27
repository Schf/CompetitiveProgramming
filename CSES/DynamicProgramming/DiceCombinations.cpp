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
		int i, j, n;
		cin >> n;
		vector <int> dp (7, 0);
		for (i = 0; i < 6; ++i)
			dp[i] = 1 << i;
		for (i = 6; i < n; ++i)
		{
			dp[i%7] = 0;
			for (j = 1; j <= 6; ++j)
				dp[i%7] = (dp[i%7] + dp[(i - j)%7]) % MOD;
		}
		cout << dp[(n - 1)%7] << '\n';
	}

	return 0;
}


