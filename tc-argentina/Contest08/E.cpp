#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+8+7;

vector <ll> sieve (MAXN, 0), primes;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;

	for (i = 2; i < MAXN; ++i)
		if (!sieve[i])
			for (j = i, primes.push_back (i); j < MAXN; j += i)
				sieve[j] = i;

	/*cin >> n >> m;
	vector <vector <ll>> inp (n, vector <ll> (primes.size () + 1, 0));
	trav (v, inp)
	{
		cin >> j;
		for (i = 0; i < primes.size (); ++i)
			while (j % primes[i] == 0 && j > 0)
				++v[i], j /= primes[i];
		if (j != 1) v[v.size () - 1] = j;
	}

	vector <pair <ll, ll>> pp (m);
	trav (p, pp) cin >> p.f >> p.s, --p.f, --p.s;
	ll ans = 0;
	trav (p, pp)
		if (inp[p.f].back () > 0 && inp[p.f].back () == inp[p.s].back ())
			++ans, inp[p.f][inp[p.f].size () - 1] =
			inp[p.s][inp[p.s].size () - 1] = 0;*/
	cout << primes.back () << '\n';

	return 0;
}

