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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, k;
		cin >> n >> k;
		map <ll, ll> inp;
		for (i = 0; i < n; ++i)
		{
			cin >> j;
			if (j % k != 0)
				++inp[j%k];
		}
		pair <ll, ll> mx = {-1, -1};
		trav (p, inp)
			if (mx.f == -1) mx = p;
			else if (mx.s < p.s) mx = p;
		if (mx.f == -1) cout << 0 << '\n';
		else cout << (mx.s - 1)*k + k-mx.f + 1 << '\n';
	}

	return 0;
}

