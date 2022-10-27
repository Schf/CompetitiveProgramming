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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	while (cin >> n)
	{
		vector <ll> inp (n), idx (n);
		trav (a, inp) cin >> a;
		sort (inp.begin (), inp.end (), greater <ll> ());
		vector <ll> out (n);
		out[0] = inp[0];
		for (i = 1; i < n; ++i)
		{
			sort (inp.begin () + i, inp.end (), [&] (auto a, auto b)
			{
				ll gcda = __gcd (out[i - 1], a);
				ll gcdb = __gcd (out[i - 1], b);
				if (gcda == gcdb) return a > b;
				return  gcda > gcdb;
			});
			out[i] = __gcd (out[i - 1], inp[i]);
		}
		trav (a, inp) cout << a << ' ';
		cout << '\n';
		//trav (a, out) cout << a << ' ';
		//cout << '\n';
	}

	return 0;
}

