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
	ll tc;
	cin >> tc;
	for (ll tcc = 1; tcc <= tc; ++tcc)
	{
		ll i, j, n;
		cin >> n;
		int mat[n][n], freq[n + 1];
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				cin >> mat[i][j];
		ll k = 0, r = 0, c = 0;
		for (i = 0; i < n; ++i)
			k += mat[i][i];
		for (i = 0; i < n; ++i)
		{
			memset (freq, 0, sizeof freq);
			bool rep = false;
			for (j = 0; j < n; ++j)
				if (freq[mat[i][j]]) rep = true;
				else freq[mat[i][j]] = 1;
			if (rep) ++r;
		}
		for (j = 0; j < n; ++j)
		{
			memset (freq, 0, sizeof freq);
			bool rep = false;
			for (i = 0; i < n; ++i)
				if (freq[mat[i][j]]) rep = true;
				else freq[mat[i][j]] = 1;
			if (rep) ++c;
		}
		cout << "Case #" << tcc << ": " << k << ' ' << r << ' ' << c << '\n';
	}

	return 0;
}

