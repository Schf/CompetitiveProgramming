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
	vector <ll> fib;
	fib.push_back (1);
	fib.push_back (1);
	for (ll i = 2; fib[i - 1] < 2e9; ++i)
		fib.push_back (fib[i - 1] + fib[i - 2]);
	ll tc = 1; cin >> tc;
	while (tc--)
	{
		ll i, j, n, a, b;
		cin >> n;
		/*ll mna = INF, mnb = INF;
		for (i = 2; i <= fib.size (); ++i)
		{
			if ((n % fib[i - 2]) % (fib[i - 1] % fib[i - 2]) == 0)
			{
				b = (n % fib[i - 2]) / (fib[i - 1] % fib[i - 2]);
				if ((n % fib[i - 1]) % (fib[i - 2] % fib[i - 1]) == 0)
				{
					a = (n % fib[i - 1]) / (fib[i - 2] % fib[i - 1]);
					if (n == fib[i - 1]*b + fib[i - 2]*a && 0 < a && a <= b && b < n)
					{
						mna = min (mna, a);
						mnb = min (mnb, b);
					}
				}
			}
		}
		a = mna, b = mnb;*/
		for (b = 1; b < 50000; ++b)
			for (i = 2; i <= fib.size () && fib[i - 1]*b < n; ++i)
				if ((n - fib[i - 1]*b)%fib[i - 2] == 0)
				{
					a = (n - fib[i - 1]*b)/fib[i - 2];
					if (a <= b && 0 < a) goto achou;
				}
		achou:;
		cout << a << ' ' << b << '\n';
	}

	return 0;
}


