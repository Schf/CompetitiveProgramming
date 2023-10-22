#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, a, b, c;
	cin >> a >> b >> c;
	vector <ll> sieve (MAXN, INF);
	for (i = 2; i < MAXN; ++i)
		if (sieve[i] >= INF)
			for (j = i*i, sieve[i] = i; j < MAXN; j += i)
				sieve[j] = min (sieve[j], i);
	vector <ll> div (MAXN, -1);
	div[0] = 0, div[1] = 1;
	ll ans = 0;
	for (i = 1; i <= a; ++i)
		for (j = 1; j <= b; ++j)
			for (ll k = 1; k <= c; ++k)
			{
				if (div[i*j*k] < 0)
				{
					div[i*j*k] = 1;
					vector <ll> cdiv (1, 1);
					for (ll l = i*j*k; l > 1; l /= sieve[l])
						if (++cdiv[cdiv.size () - 1] && sieve[l]
								!= sieve[l/sieve[l]])
							cdiv.push_back (1);
					trav (a, cdiv)
						div[i*j*k] = (div[i*j*k] * a) % MOD;
				}
				ans = (ans + div[i*j*k]) % MOD;
			}
	cout << ans << '\n';
	
	return 0;
}

