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
		vector <int> dp (n + 1, INF);
		dp[n] = 0;
		for (i = n; i >= 0; --i)
			for (j = i; j > 0; j /= 10)
				if (i - j%10 >= 0)
					dp[i - j%10] = min (dp[i - j%10], dp[i] + 1);
		//for (i = 0; i < dp.size (); ++i) printf (" % 4d", i);
		//printf ("\n");
		//trav (a, dp) printf (" % 4d", a<INF?a:-1);
		//printf ("\n");
		cout << dp[0] << '\n';
	}

	return 0;
}


