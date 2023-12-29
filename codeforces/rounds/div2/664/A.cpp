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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, r, g, b, w;
		cin >> r >> g >> b >> w;
		for (i = 0; i < 1e4; ++i)
			if (!r||!g||!b) break;
			else if ((r%2)+(g%2)+(b%2)+(w%2) >= 2)
				--r, --g, --b, w += 3;
		if ((r%2)+(g%2)+(b%2)+(w%2) >= 2)
			cout << "No\n";
		else cout << "Yes\n";
	}

	return 0;
}

