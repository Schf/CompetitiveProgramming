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
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, a, b, c, d;
		cin >> a >> b >> c >> d;
		ll x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (((b != 0 || a != 0) && x2 - x1 < 1) || ((d != 0 || c != 0) && y2 - y1 < 1))
			cout << "No\n";
		else if (x1 <= b - a + x && b - a + x <= x2 && y1 <= d - c + y && d - c + y <= y2)
			cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}


