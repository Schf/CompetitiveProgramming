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
	ll i, j, n, q;
	cin >> n;
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	cin >> q;
	for (ll qq = 0; qq < q; ++qq)
	{
		cin >> i >> j; --i;
		if (i > 0) inp[i - 1] += j - 1;
		if (i < n - 1) inp[i + 1] += inp[i] - j;
		inp[i] = 0;
	}
	trav (a, inp) cout << a << '\n';

	return 0;
}

