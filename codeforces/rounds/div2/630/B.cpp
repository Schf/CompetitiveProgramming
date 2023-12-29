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

vector <ll> sieve (1001, INF);

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	ll tc;
	cin >> tc;
	for (ll i = 2; i < 1001; ++i)
		if (sieve[i] >= INF)
			for (ll j = i; j < 1001; j += i)
				sieve[j] = min (sieve[j], i);
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> out (n);
		set <ll> freq;
		trav (a, out) cin >> j, a = sieve[j], freq.insert (sieve[j]);
		auto itt = freq.begin ();
		for (i = 1; itt != freq.end (); ++i, ++itt)
			trav (a, out) if (a == *itt) a = i;
		ll mx = 0;
		trav (a, out) mx = max (mx, a);
		cout << mx << '\n';
		trav (a, out) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}


