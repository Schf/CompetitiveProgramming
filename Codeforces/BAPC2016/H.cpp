#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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
	ll i, j, n, b, x;
	cin >> b >> n;
	vector <ll> primes, sieve (b), fact;
	primes.reserve (b);
	fact.reserve (100);
	for (i = 2; i < b; ++i)
	{
		if (!sieve[i])
		{
			for (sieve[i] = i, j = i*i; j < b; j += i)
				sieve[j] = i;
			primes.push_back (i);
		}
	}
	x = n;
	for (i = 0; i < primes.size (); ++i)
		while (!(x%primes[i])) fact.push_back (primes[i]), x /= primes[i];
	if (x > 1)
	{
		cout << "impossible\n";
		return 0;
	}
	sort (fact.begin (), fact.end ());
	vector <bool> viz (fact.size (), false);
	vector <ll> ansvec;
	for (i = fact.size () - 1; i >= 0; --i)
	{
		if (viz[i]) continue;
		ll num = fact[i];
		viz[i] = true;
		for (j = i - 1; j >= 0; --j)
		{
			if (viz[j]) continue;
			if (num * fact[j] < b)
				num *= fact[j], viz[j] = true;
		}
		ansvec.push_back (num);
	}
	ll ans = 0;
	sort (ansvec.begin (), ansvec.end (), greater <ll> ());
	for (i = 0, j = 1; i < ansvec.size (); j *= b, ++i)
		ans += ansvec[i]*j;
	cout << ans << '\n';

	return 0;
}


