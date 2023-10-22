#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 2e+5+7;

inline ll f (ll k)
{
	return ceil ((sqrt (1 + 8*k) - 1)/2);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	while (n--)
	{
		ll a, b;
		cin >> a >> b;
		ll pos1 = f (b);
		for (i = 0; i < a - pos1 - 1; ++i) cout << 'a';
		cout << 'b';
		for (++i, j = 0; j < pos1*(pos1+1)/2 - b; ++i, ++j) cout << 'a';
		cout << 'b';
		for (++i; i < a; ++i) cout << 'a';
		cout << '\n';
	}

	return 0;
}


