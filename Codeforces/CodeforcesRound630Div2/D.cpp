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

ll f (ll k)
{
	ll ans = 1;
	while (ans <= k) ans <<= 1;
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, k;
	cin >> k;
	cout << 2 << ' ' << 3 << '\n';
	cout << (f (k) | k) << ' ' << k << ' ' << 0 << '\n';
	cout << f (k) << ' ' << (f (k) | k) << ' ' << k << '\n';

	return 0;
}

