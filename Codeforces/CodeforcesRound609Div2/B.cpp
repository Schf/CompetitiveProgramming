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
	cin >> n >> MOD;
	vector <ll> A (n), B (n), P (n);
	trav (a, A) cin >> a;
	trav (a, B) cin >> a;
	sort (A.begin (), A.end ());
	sort (B.begin (), B.end ());
	ll ans = INF;
	for (j = 0; j < n; ++j)
	{
		for (i = 0; i < n; ++i)
			P[i] = (A[i] + B[j] - A[0] + MOD)%MOD;
		sort (P.begin (), P.end ());
		if (P == B)
			ans = min (ans, (B[j] - A[0] + MOD) % MOD);
	}
	cout << ans << '\n';

	return 0;
}

