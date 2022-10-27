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

vector <ll> primes, sieve (1e7+1, 0), tree;

void update (int pos)
{
	pos += primes.size ();
	++tree[pos];
	for (pos >>= 1; pos > 0; pos >>= 1)
		tree[pos] = tree[pos << 1] * tree[pos << 1 | 1] % MOD;
}

ll query (int r)
{
	ll l = 0, ans = 1;
	for (l += primes.size (), r += primes.size (); l < r; l >>= 1, r >>= 1)
	{
		if (l&1) ans = ans * tree[l++] % MOD;
		if (r&1) ans = ans * tree[--r] % MOD;
	}
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	primes.reserve (664579);
	primes.push_back (2);
	for (int i = 2; i < (int)1e7+1; i += 2)
		sieve[i] = 2;
	for (ll i = 3; i < (int)1e7+1; i += 2)
		if (!sieve[i])
		{
			primes.push_back (i);
			for (ll j = i*i; j < (int)1e7+1; j += i)
				sieve[j] = i;
		}
	tree.resize (2*primes.size ());
	while (tc--)
	{
		ll i, j, n, p;
		cin >> n;
		map <int, int> revp;
		
		for (i = 0; i < primes.size (); ++i)
		{
			revp[primes[i]] = i;
			++tree[i + primes.size ()];
			while (!(n%primes[i]))
				++tree[i + primes.size ()],
				n /= primes[i];
		}
		for (i = primes.size () - 1; i > 0; --i)
			tree[i] = tree[i << 1] * tree[i << 1 | 1] % MOD;
		while (cin >> p)
		{
			int pos = revp[p];
			update (pos);
			cout << query (pos) << '\n';
		}
	}

	return 0;
}


