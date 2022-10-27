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

int fac (int a)
{
	if (a <= 1) return 1;
	return a*fac (a - 1);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; cin >> tc;
	while (tc--)
	{
		int i, j, n;
		cin >> n;
		map <string, int> cc;
		for (i = 0; i < n; ++i)
		{
			string str;
			cin >> str; cin >> str;
			(cc[str])++;
		}
		int ans = 1;
		trav (p, cc)
			ans *= (p.s + 1);
		cout << ans - 1 << '\n'; 
	}

	return 0;
}


