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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> A (n), B (n);
		trav (a, A) cin >> a;
		trav (a, B) cin >> a;
		ll na = *min_element (A.begin (), A.end ());
		ll nb = *min_element (B.begin (), B.end ());
		ll ans = 0;
		for (i = 0; i < n; ++i)
			ans += max (A[i] - na, B[i] - nb);
		cout << ans << '\n';
	}

	return 0;
}

