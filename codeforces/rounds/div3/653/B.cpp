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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		for (i = 0; n >= 3 && n%3 == 0; ++i)
			n /= 3;
		for (j = 0; n >= 2 && n%2 == 0; ++j)
			n /= 2;
		if (n > 1 || j > i) cout << -1 << '\n';
		else cout << 2*i - j << '\n';
	}

	return 0;
}

