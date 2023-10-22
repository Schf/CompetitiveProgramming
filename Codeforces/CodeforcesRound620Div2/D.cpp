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
		int i, j, n;
		string cmp;
		cin >> n >> cmp;
		vector <int> mn (n), mx (n), vn (n), vx (n);
		for (i = j = 0; i < n; ++i) if (cmp[i] == '<') mn[i] = j, vn[j++] = 1;
		for (i = n - 1, j = 0; i >= 0; --i) if (cmp[i] == '<') mx[i] = j, vx[j++] = 1;
		trav (a, mn) cout << a << ' '; cout << '\n';
		trav (a, mx) cout << a << ' '; cout << '\n';
	}

	return 0;
}


