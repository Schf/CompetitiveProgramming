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

vector <ll> sieve (MAXN), primes;

inline ll pow (ll v, ll p)
{
	if (p < 1) return 1;
	if (p == 1) return v;
	ll mult = 1;
	if (p&1) mult = v;
	return mult * pow (v, p/2) * pow (v, p/2);
}

inline bool OK (ll a, ll b, vector <ll> & c)
{
	if (__gcd (a, c[0]) == 1) return false;
	for (ll i = 1; i < c.size (); ++i)
		if (__gcd (c[i - 1], c[i]) == 1) return false;
	if (__gcd (c.back (), b) == 1) return false;
	return true;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	for (i = 2; i < MAXN; ++i)
		if (!sieve[i])
			for (primes.push_back (i), sieve[i] = i, j = i*i; j < MAXN; j += i)
				sieve[j] = i;
	cin >> n;
	while (cin >> n)
	{
		vector <pair <ll, ll>> fact;
		for (i = 0, j = n; j > 1; ++i)
		{
			if (j%primes[i] == 0)
			{
				fact.push_back ({primes[i], 0});
				while (j%primes[i] == 0)
					++fact[fact.size () - 1].s,
					j /= primes[i];
			}
		}
		ll div_amt = 1;
		trav (p, fact) div_amt *= p.s + 1;
		--div_amt;
		vector <ll> order (div_amt);
		ll ordi = 0, facti = 0;
		for (i = 1; i <= fact[0].s; ++i)
			order[ordi++] = pow (fact[0].f, i);
		if (fact.size () == 1)
		{
			trav (a, order) cout << a << ' ';
			cout << "\n0\n";
			continue;
		}
		if (fact.size () == 2)
		{
			if (div_amt == 3)
			{
				order[1] = fact[0].f*fact[1].f;
				order[2] = fact[1].f;
				trav (a, order) cout << a << ' ';
				cout << "\n1\n";
				continue;
			}
			for (i = 1; i <= fact[0].s; ++i)
				for (j = 1; j <= fact[1].s; ++j)
					order[ordi++] = pow (fact[0].f, i)*
							pow (fact[1].f, j);
			--ordi;
			for (i = 1; i <= fact[1].s; ++i)
				order[ordi++] = pow (fact[1].f, i);
			order[ordi++] = n;
			trav (a, order) cout << a << ' ';
			cout << "\n0\n";
			continue;
		}
		for (facti = 1; facti < fact.size (); ++facti)
		{
			for (i = 1; i <= fact[facti - 1].s; ++i)
				for (j = 1; j <= fact[facti].s; ++j)
					order[ordi++] = pow (fact[facti - 1].f, i)*
							pow (fact[facti].f, j);
			for (i = 1; i <= fact[facti].s; ++i)
				order[ordi++] = pow (fact[facti].f, i);
		}
		for (i = 1; i <= fact[facti - 1].s; ++i)
			for (j = 1; j <= fact[0].s; ++j)
				order[ordi++] = pow (fact[facti - 1].f, i)*
						pow (fact[0].f, j);
		set <ll> missing;
		ll lim = sqrt (n) + 1;
		for (i = 2; i < lim; ++i)
			if (n%i == 0)
				missing.insert (i), missing.insert (n/i);
		missing.insert (n);
		for (i = 0; i < ordi; ++i)
			missing.erase (order[i]);
		vector <ll> misv;
		trav (a, missing) misv.push_back (a);
		while (!OK (order[ordi - 1], order[0], misv))
			random_shuffle (misv.begin (), misv.end ());
		trav (a, misv) order[ordi++] = a;
		trav (a, order) cout << a << ' ';
		cout << "\n0\n";
	}

	return 0;
}

