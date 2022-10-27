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

void bin (ll a)
{
	vector <char> out (8, 0);
	cout << ' ';
	for (ll i = 0; a > 0; ++i, a >>= 1)
		out[i] = a&1;
	for (ll i = out.size () - 1; i >= 0; --i)
		cout << (int) out[i];
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	vector <ll> A (n), B (m);
	trav (a, A) cin >> a;
	trav (a, B) cin >> a;
	vector <vector <ll>> T (n, vector <ll> (m)),
			Dp (n, vector <ll> (m, INF));
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			T[i][j] = A[i] & B[j];
	sort (T.begin (), T.end (), [&] (auto & a, auto & b)
	{
		return *min_element (a.begin (), a.end ()) <
				*min_element (b.begin (), b.end ());
	});
	Dp[0] = T[0];
	for (i = 1; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
			for (ll k = 0; k < m; ++k)
				Dp[i][j] = min (Dp[i][j], T[i][j] | Dp[i - 1][k]);
	}
	/*trav (v, T)
	{
		trav (a, v)
			bin (a);
		cout << '\n';
	}
	cout << '\n';
	trav (v, Dp)
	{
		trav (a, v )
			bin (a);
		cout << '\n';
	}
	cout << '\n';*/
	ll ans = INF;
	trav (a, Dp[n - 1]) ans = min (ans, a);
	cout << ans << '\n';

	return 0;
}

