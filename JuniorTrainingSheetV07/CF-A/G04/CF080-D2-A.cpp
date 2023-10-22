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

vector <ll> primes, sieve (100);

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	for (i = 2; i < 100; ++i)
		if (!sieve[i])
			for (primes.push_back (i), j = i; j < 100; j += i)
				sieve[j] = i;
	cin >> n >> m;
	if (sieve[n] == n && *(++find (primes.begin (), primes.end (), n)) == m)
		cout << "YES\n";
	else cout << "NO\n";

	return 0;
}

