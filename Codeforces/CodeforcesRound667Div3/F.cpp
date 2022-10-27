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
	string s, t;
	cin >> s >> t;
	vector <ll> pf (n), sf (n);
	for (ll l = 0, r = n - 1; k > 0; --k)
	{
		pf[0] = (s[0] == t[0]);
		for (i = 1; i < n; ++i)
			pf[i] = pf[i - 1] + (s[i] == t[0]);
		sf[n - 1] = (s[n - 1] == t[1]);
		for (i = n - 2; i >= 0; --i)
			sf[i] = sf[i + 1] + (s[i] == t[1]);
		l = 0, r = n - 1;
		while (s[l] == t[0]) ++l;
		while (s[r] == t[1]) --r;
		ll pos, qnt;
		char c;
		for (j = l; j <= r; ++j)
		{
			if (s[j] != t[0] && j < n - 1)
				if (qnt < sf[j + 1])
					qnt = sf[j + 1]
		}
		if (sf[l + 1] > pf[r - 1]) s[l] = t[0];
		else s[r] = t[1];
	}
	//cout << s << '\n';
	ll ans = 0;
	for (i = 0; i < n; ++i)
		if (s[i] == t[0])
			for (j = i + 1; j < n; ++j)
				if (s[j] == t[1]) ++ans;
	cout << ans << '\n';

	return 0;
}

