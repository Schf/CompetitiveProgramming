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
	ll i, j, n, a, b, c = 0, ans = 0;
	cin >> n >> a >> b;
	for (i = 0; i < n; ++i)
	{
		cin >> j;
		if (j == 1)
			if (a <= 0)
				if (b <= 0)
					if (c <= 0) ++ans;
					else --c;
				else --b, ++c;
			else --a;
		else
			if (b <= 0) ans += 2;
			else --b;
	}
	cout << ans << '\n';

	return 0;
}

