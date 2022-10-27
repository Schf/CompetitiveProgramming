#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	while (cin >> n)
	{
		vector <ll> inp (n);
		trav (a, inp)
		{
			cin >> a;
			for (i = 0; a > 1; a >>= 1, ++i);
			a = i;
		}
		vector <vector <ll>> prf (31, vector <ll> (n));
		for (i = 0; i < n; ++i)
			prf[inp[i]][i] = 1;
		for (i = 0; i < 31; ++i)
			for (j = n - 2; j >= 0; --j)
				prf[i][j] += prf[i][j + 1];
		ll ans = 0;
		for (i = 0; i < n - 1; ++i)
			ans += prf[inp[i]][i + 1];
		cout << ans << '\n';
	}

	return 0;
}
