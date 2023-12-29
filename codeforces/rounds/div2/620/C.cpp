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
	int tc; cin >> tc;
	while (tc--)
	{
		int i, j, n, m;
		cin >> n >> m;
		vector <ll> T (n), L (n), H (n);
		for (i = 0; i < n; ++i)
			cin >> T[i] >> L[i] >> H[i];
		vector <pair <ll, ll>> dp (n, {1, 0});
		dp[0].f = max (L[0], m - T[0]); dp[0].s = min (H[0], m + T[0]);
		for (i = 1; i < n; ++i)
			dp[i].f = max (L[i], dp[i - 1].f - (T[i] - T[i - 1])),
			dp[i].s = min (H[i], dp[i - 1].s + (T[i] - T[i - 1]));
		//trav (p, dp) cout << "<" << p.f << ", " << p.s << "> ";
		//cout << '\n';
		bool ans = true;
		for (i = 0; i < n && ans; ++i)
			if (dp[i].f > dp[i].s)
				ans = false;
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


