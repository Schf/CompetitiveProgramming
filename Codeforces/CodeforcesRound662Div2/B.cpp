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
	ll i, j, n, q, f2 = 0, f4 = 0, f6 = 0, f8 = 0;
	cin >> n;
	vector <ll> inp (n), freq (MAXN, 0);
	trav (a, inp) cin >> a, ++freq[a];
	trav (a, freq)
		f2 += (a >= 2),
		f4 += (a >= 4),
		f6 += (a >= 6),
		f8 += (a >= 8);
	cin >> q;
	for (i = 0; i < q; ++i)
	{
		char c;
		cin >> c >> j;
		if (c == '-')
			--freq[j],
			f2 -= (freq[j] == 1),
			f4 -= (freq[j] == 3),
			f6 -= (freq[j] == 5),
			f8 -= (freq[j] == 7);
		if (c == '+')
			++freq[j],
			f2 += (freq[j] == 2),
			f4 += (freq[j] == 4),
			f6 += (freq[j] == 6),
			f8 += (freq[j] == 8);
		if (f8) cout << "YES\n";
		else if (f6 && f2 >= 2) cout << "YES\n";
		else if (f4 >= 2) cout << "YES\n";
		else if (f4 && f2 >= 3)cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

