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
	while (tc--)
	{
		ll i, j, n, k;
		cin >> n >> k;
		vector <ll> inp (n), fq (2*k + 1), mx (2*k + 1), mn (2*k + 1);
		trav (a, inp) cin >> a;
		for (i = 0; i < n/2; ++i)
			++mx[k + max (inp[i], inp[n - i - 1])],
			++mn[1 + min (inp[i], inp[n - i - 1])],
			++fq[inp[i] + inp[n - i - 1]];
		for (i = mx.size () - 2; i >= 0; --i)
			mx[i] += mx[i + 1];
		for (i = 1; i < mn.size (); ++i)
			mn[i] += mn[i - 1];
		ll ans = INF;
		for (i = 0; i < fq.size (); ++i)
			ans = min (ans, 3*n/2 - mx[i] - mn[i] - fq[i]);
		cout << ans << '\n';
		/*for (i = 0; i < fq.size (); ++i)
			printf (" % 4lld", i);
		printf ("\n");
		trav (a, mx)
			printf (" % 4lld", a);
		printf ("\n");
		trav (a, mn)
			printf (" % 4lld", a);
		printf ("\n");
		trav (a, fq)
			printf (" % 4lld", a);
		printf ("\n=========================== % 4lld\n", ans);*/
	}

	return 0;
}

