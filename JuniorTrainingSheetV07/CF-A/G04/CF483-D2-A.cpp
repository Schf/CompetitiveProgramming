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
	ll i, j, l, r;
	cin >> l >> r;
	for (ll a = l; a <= r - 2; ++a)
		for (ll b = a + 1; b <= r - 1; ++b)
			for (ll c = b + 1; c <= r; ++c)
				if (__gcd (a, b) == 1 && __gcd (b, c) == 1 && __gcd (a, c) != 1)
				{
					cout << a << ' ' << b << ' ' << c << '\n';
					return 0;
				}
	cout << -1 << '\n';

	return 0;
}

