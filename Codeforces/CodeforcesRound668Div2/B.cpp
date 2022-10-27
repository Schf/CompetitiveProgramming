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
		ll ans = 0, l = 0, r = n - 1, ls = 0, rs = 0;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		while (l < r)
		{
			for (; l < n && inp[l] >= 0; ls += inp[l++]);
			for (; r >= 0 && inp[r] <= 0; rs += inp[r--]);
			if (l >= r) break;
			inp[l] = ls = inp[l] + ls;
			inp[l] = min (0LL, inp[l]);
			ls = max (0LL, ls);
			inp[r] = rs = inp[r] + rs;
			inp[r] = max (0LL, inp[r]);
			rs = min (0LL, rs);
			ans += max (-inp[l], inp[r]);
			inp[l] = inp[r] = inp[l] + inp[r];
			inp[l] = max (0LL, inp[l]);
			inp[r] = min (0LL, inp[r]);
		}
		cout << ans << '\n';
	}

	return 0;
}

