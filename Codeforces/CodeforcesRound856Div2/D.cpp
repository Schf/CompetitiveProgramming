#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

ll MOD = 1e+9 + 7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6 + 7;

vll sieve(MAXN), primes;

inline bool prime(ll &a)
{
	return sieve[a] == a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i, j, n;

	for (i = 2; i < MAXN; ++i)
		if (!sieve[i])
			for (primes.push_back(sieve[i] = i), j = i * i; j < MAXN; j += i)
				sieve[j] = i;

	cin >> n;
	vll v(MAXN);
	ll pn, nn;
	for (i = 0; i < 2 * n; ++i)
		cin >> j, v[j]++, nn++, pn += prime(j);

	vll ns, ps;
	for (i = 0; i < MAXN; ++i)
		if (v[i])
			ns.push_back(v[i]), ps.push_back(prime(i) ? v[i] : 0);

	trav(e, ns) cout << e << ' ';
	cout << endl;
	trav(e, ps) cout << e << ' ';
	cout << endl;

	ll ans = 0;
	for (i = 0; i < ns.size (); ++i)
		if (ps[i])
			for (j = 0; j < i; ++j)
				
				

	return 0;
}
