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

vector <ll> primes, sieve (MAXN);

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	primes.reserve (MAXN);
	for (i = 2; i < MAXN; ++i)
		if (!sieve[i])
			for (primes.push_back (i), j = i; j < MAXN; j += i)
				sieve[j] = i;
	cin >> n;
	while (n)
	{
		vector <ll> fac;
		for (i = 0; i < primes.size () && n > 1; ++i)
		{
			if (n%primes[i] == 0)
			{
				fac.push_back (0);
				while (n%primes[i] == 0)
					++fac[fac.size () - 1],
					n /= primes[i];
			}
		}
		if (n > 1) fac.push_back (n);
		ll ans = 1;
		for (i = 0; i < fac.size (); ++i)
			ans *= fac[i] + 1;
		if (ans&1) cout << "yes\n";
		else cout << "no\n";

		cin >> n;
	}

	return 0;
}

