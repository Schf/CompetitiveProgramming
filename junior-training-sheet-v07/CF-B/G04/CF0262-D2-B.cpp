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
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	sort (inp.begin (), inp.end ());
	ll d0 = n, d1 = n;
	for (i = 0; i < n; ++i)
	{
		if (inp[i] >= 0 && d0 > i) d0 = i;
		if (inp[i] > 0 && d1 > i) d1 = i;
	}
	ll ans = 0;
	for (i = 0; i < k && i < d0; ++i)
		inp[i] = abs (inp[i]);
	for (i = 0; i < n; ++i)
		ans += inp[i];
	if (k > d0 && (k - d0)%2)
		ans -= 2*(*min_element (inp.begin (), inp.end ()));
	cout << ans << '\n';


	return 0;
}

