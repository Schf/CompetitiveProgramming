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

ll biggest2exp (ll a)
{
	if (a <= 0) return 0;
	ll ans = 0; --a;
	while (a = a >> 1) ++ans;
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc;
	cin >> tc;
	vector <vector <ll>> trig (60, vector <ll> (60, 1));
	for (ll i = 3; i < trig.size (); ++i)
		for (ll j = 2; j < i; ++j)
			trig[i][j] = trig[i - 1][j - 1] + trig[i - 1][j];
	for (ll tcc = 1; tcc <= tc; ++tcc)
	{
		ll i, j, n;
		cin >> n;
		if (n <= 500)
		{
			cout << "Case #" << tcc << ":\n";
			for (i = 1; i <= n; ++i)
				cout << i << ' ' << i << '\n';
			continue;
		}
		cout << "Case #" << tcc << ":\n";
		vector <ll> gos;
		for (i = 0, j = n - 32; j > 0; ++i, j >>= 1)
			if (j & 1)
				gos.push_back (i);
		vector <pair <ll, ll>> out;
		for (i = j = 0; i <= gos.back (); ++i)
			if (i == gos[j])
			{
				if (j&1)
					for (ll k = i; k >= 0; --k)
						cout << i + 1 << ' ' << k + 1 << '\n';
				else
					for (ll k = 0; k <= i; ++k)
						cout << i + 1 << ' ' << k + 1 << '\n';
				++j;
			}
			else
				cout << i + 1 << ' ' << ((j&1)?(i + 1):(1)) << '\n';
		for (j = i - gos.size (); j < 32; ++i, ++j)
			cout << i + 1 << ' ' << ((gos.size ()&1)?(i + 1):(1)) << '\n';
		
	}

	return 0;
}

