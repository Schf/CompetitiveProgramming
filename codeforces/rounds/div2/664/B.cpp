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
	ll i, j, n, m, x, y;
	cin >> n >> m >> x >> y;
	set <pair <ll, ll>> gone;
	cout << x << ' ' << y << '\n';
	cout << x << ' ' << 1 << '\n';
	gone.insert ({x, y});
	gone.insert ({x, 1});
	for (j = 1; j <= m; ++j)
	{
		if (j%2)
		{
			for (i = 1; i <= n; ++i)
				if (gone.find ({i, j}) == gone.end ())
					cout << i << ' ' << j << '\n';

		}
		else
		{
			for (i = n; i >= 1; --i)
				if (gone.find ({i, j}) == gone.end ())
					cout << i << ' ' << j << '\n';
		}
	}

	return 0;
}

