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

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, m, k;
		cin >> n >> m >> k;
		for (i = 0; i < k; ++i) cin >> j >> j;
		string out;
		for (i = 1; i < n; ++i) out += 'U';
		for (j = 1; j < m; ++j) out += 'L';
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j < m; ++j) out +=  (char)((i&1)?('R'):('L'));
			if (i < n) out += 'D';
		}
		cout << out.size () << '\n' << out << '\n';
	}

	return 0;
}


