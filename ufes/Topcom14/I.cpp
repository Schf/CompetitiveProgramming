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
		ll i, j, n, x1, x2, x3, y1, y2, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		if (x1 > x2) swap (x1, x2);
		if (y1 > y2) swap (y1, y2);
		if (x3 < x1 || x2 < x3 || y3 < y1 || y2 < y3) cout << "FORA\n";
		else if (x3 == x1 || x2 == x3 || y3 == y1 || y2 == y3) cout << "BORDA\n";
		else cout << "DENTRO\n";
	}

	return 0;
}

