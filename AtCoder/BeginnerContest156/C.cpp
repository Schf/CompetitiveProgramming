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
const ll MAXN = 1e+3+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n;
		cin >> n;
		vector <int> given (n), tests (3*MAXN, 0);
		trav (a, given) cin >> a;
		for (i = -MAXN; i < 2*MAXN; ++i)
			for (j = 0; j < n; ++j)
				tests[i + MAXN] += (given[j] - i)*(given[j] - i);
		int ans = INF;
		trav (a, tests)
			ans = min (ans, a);
		cout << ans << '\n';
	}

	return 0;
}


