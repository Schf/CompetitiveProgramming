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
	ll i, j, n;
	cin >> n;
	while (cin >> n)
	{
		ll sum = 0;
		for (i = 0; i < n; ++i)
			cin >> j, sum += j;
		if (sum > n/2)
		{
			cout << n/2 + (n/2)%2 << '\n';
			for (i = 0; i < n/2; ++i)
				cout << "1 ";
			if ((n/2)%2) cout << "1 ";
			cout << '\n';
		}
		else
		{
			cout << n/2 << '\n';
			for (i = 0; i < n/2; ++i)
				cout << "0 ";
			cout << '\n';
		}
	}

	return 0;
}

