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
	for (i = 0; i < 5; ++i)
		for (j = 0; j < 5; ++j)
		{
			cin >> n;
			if (n == 1) goto out;
		}
	out:;
	cout << abs (2 - i) + abs (2 - j) << '\n';

	return 0;
}

