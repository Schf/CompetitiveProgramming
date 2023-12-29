#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

vector <ll> sieve (MAXN, 0);

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, a, b, k;
	cin >> a >> b >> k;
	for (i = 2; i < MAXN; ++i)
		if (!sieve[i])
			for (sieve[i] = i, j = i*i; j < MAXN; j += i)
				sieve[j] = i;
	n = b - a + 1;
	vector <ll> alg (n, 0), suf (n + 1, 0);
	for (i = 0; i < n; ++i)
		alg[i] = (sieve[a + i] == a + i);
	for (i = n - 1; i >= 0; --i)
		suf[i] = alg[i] + suf[i + 1];
	if (suf[0] < k)
	{
		cout << "-1\n";
		return 0;
	}
	//trav (a, alg) cout << a << ' ';
	//cout << '\n';
	//trav (a, suf) cout << a << ' ';
	//cout << '\n';
	ll ans = n;
	for (ll step = n/2; step > 0; step /= 2)
		while (ans - step >= 0)
		{
			bool can = true;
			for (i = 0; can && i + ans - step - 1 < n; ++i)
				if (suf[i] - suf[i + ans - step] < k)
					can = false;
			//cout << ans - step << " | ";
			//for (i = 0; i + ans - step - 1 < n; ++i)
			//	cout << suf[i] - suf[i + ans - step] << ' ';
			//cout << '\n';
			if (can) ans -= step;
			else break;
		}
	cout << ans << '\n';

	return 0;
}

