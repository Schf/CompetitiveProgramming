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
		int i, j, n, x;
		cin >> n >> x;
		vector <int> w (n), v (n), dp (x + 1, 0);
		trav (a, w) cin >> a;
		trav (a, v) cin >> a;
		for (i = 0; i < n; ++i)
			for (j = x - w[j]; j >= 0; --j)
				dp[j + w[i]] = max (dp[j + w[i]], dp[j] + v[i]);
		cout << dp[x] << '\n';
	}

	return 0;
}


