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
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> inp (n), dp;
		trav (a, inp) cin >> a;
		dp.reserve (n);
		dp.push_back (inp[0]);
		for (i = 1; i < n; ++i)
		{
			if (inp[i] < dp[0]) dp[0] = inp[i];
			else if (dp[dp.size () - 1] < inp[i]) dp.push_back (inp[i]);
			else
			{
				ll ub = dp.size () - 1, lb = -1, mb;
				while (ub - lb > 1)
				{
					mb = (ub + lb) / 2;
					if (dp[mb] < inp[i]) lb = mb;
					else ub = mb;
				}
				dp[ub] = inp[i];
			}
		}
		cout << dp.size () << '\n';
	}

	return 0;
}

