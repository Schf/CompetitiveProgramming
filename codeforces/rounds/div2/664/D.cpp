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
	ll i, j, n, d, m;
	cin >> n >> d >> m;
	vector <ll> inp (n), summ (n);
	trav (a, inp) cin >> a;
	sort (inp.begin (), inp.end ());
	ll mark = n;
	for (i = 0; i < n; ++i)
		if (inp[i] > m)
		{
			mark = i;
			break;
		}
	for (i = 0; i < d; ++i)
		summ[d - 1] += inp[i];
	for (i = d; i < n; ++i)
		summ[i] = inp[i] + summ[i - 1];
	if (mark == n)
	{
		ll ans = 0;
		trav (a, inp) ans += a;
		cout << ans << '\n';
		return 0;
	}
	ll ans = 0;
	ll big, med, sml;
	for (big = n - 1, med = mark - 1, sml = 0; sml < big; )
	{
		while ()
	}


	return 0;
}

