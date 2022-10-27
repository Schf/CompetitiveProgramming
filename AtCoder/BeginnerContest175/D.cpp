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
	ll i, j, n, k;
	cin >> n >> k;
	vector <ll> P (n), C (n), S (n);
	trav (a, P) cin >> a, --a;
	trav (a, C) cin >> a;
	for (i = 0; i < n; ++i)
	{
		ll curpos = P[i];
		ll curpnt = S[i] = C[curpos];
		vector <ll> endpos;
		endpos.push_back (curpnt);
		while (curpos != i)
			curpos = P[curpos],
			curpnt += C[curpos],
			endpos.push_back (curpnt);
		if (curpnt >= 0)
		{
			S[i] = -INFLL;
			for (j = 0; j < k%endpos.size (); ++j)
				S[i] = max (S[i], endpos[(j+1)%endpos.size ()]);
			S[i] += curpnt*(k/endpos.size ());
		}
		else
		{
			S[i] = -INFLL;
			for (j = 0; j < min ((ll)endpos.size (), k); ++j)
				S[i] = max (S[i], endpos[(j+1)%endpos.size ()]);
		}
	}
	ll ans = -INFLL;
	for (i = 0; i < n; ++i)
		ans = max (ans, S[i]);
	cout << ans << '\n';

	return 0;
}

