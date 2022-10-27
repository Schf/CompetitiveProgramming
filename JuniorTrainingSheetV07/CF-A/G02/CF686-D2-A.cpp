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
	ll i, j, n, x, d = 0;
	char c = 0;
	cin >> n >> x;
	for (i = 0; i < n; ++i)
	{
		while (c != '+' && c != '-') cin >> c;
		cin >> j;
		if (c == '+') x += j;
		if (c == '-')
			if (j <= x) x -= j;
			else ++d;
		c = 0;
	}
	cout << x << ' ' << d << '\n';

	return 0;
}

