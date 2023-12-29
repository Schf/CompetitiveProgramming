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
	ll i, j, n;
	cin >> n;
	while (n)
	{
		ll c1, n1, c2, n2, m2;
		cin >> c1 >> n1 >> c2 >> n2;
		bool swaped = false;
		if ((double)n1/c1 < (double)n2/c2)
			swap (c1, c2), swap (n1, n2), swaped = true;
		for (m2 = 0; n > 0 && n%n1; ++m2, n -= n2);
		if (n < 0) cout << "failed\n";
		else if (swaped) cout << m2 << ' ' << n/n1 << '\n';
		else cout << n/n1 << ' ' << m2 << '\n';

		cin >> n;
	}

	return 0;
}

