#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 123456789;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, l, s;
	cin >> l >> s;

	ll lim = 15;

	printf ("     ");
	for (i = 1; i <= lim; ++i)
		printf ("% 7lld", i);
	printf ("\n");
	vector <vector <ll>> dp (lim + 1, vector <ll> (lim + 1, 0));
	for (i = 1; i <= lim; ++i)
	{
		printf ("% 7lld", i);
		for (j = 1; j <= i; ++j)
		{
			ll ans = 0;
			for (int k = 1; k < (1 << i); ++k)
			{
				ll dist = 1, cur_dist = 1;
				for (int l = (k << i) + k; l > 0; l >>= 1)
				{
					if (l & 1) cur_dist = 1;
					else dist = max (dist, ++cur_dist);
				}
				if (dist <= j) ++ans;
			}
			dp[i][j] = ans;
			printf ("% 7lld", dp[i][j] - dp[i][j - 1]);
		}
		printf ("\n");
	}

	return 0;
}


