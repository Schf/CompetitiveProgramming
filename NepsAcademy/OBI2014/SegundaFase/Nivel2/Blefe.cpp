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
		int i, j, n, m;
		cin >> n >> m;
		set <ll> A, B;
		for (i = 0; i < n; ++i)
		{
			cin >> j;
			A.insert (j);
		}
		for (i = 0; i < m; ++i)
		{
			cin >> j;
			bool ans = (A.find (j) != A.end ()) || (B.find (j) != B.end ());
			auto l = B.begin ();
			auto r = B.rbegin ();
			while (!ans && l != B.end () && r != B.rend () && *l <= *r)
				if (*l + *r == j) ans = true;
				else if (*l + *r < j) ++l;
				else ++r;
			if (!ans)
			{
				cout << j << '\n';
				break;
			}
			else B.insert (j);
		}
		if (i >= m) cout << "sim\n";
		//for (; i < m; ++i)
		//	cin >> j;
	}

	return 0;
}

