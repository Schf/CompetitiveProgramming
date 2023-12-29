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
	ll i, j, n, x;
	cin >> n;
	while (cin >> n >> x)
	{
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		bool trivial = true;
		for (i = 0; i < n && trivial; ++i)
			if (inp[i] != x) trivial = false;
		if (trivial)
		{
			cout << 0 << '\n';
			continue;
		}
		ll sum = 0;
		for (i = 0; i < n; ++i)
			sum += inp[i];
		if (sum == x*n)
		{
			cout << 1 << '\n';
			continue;
		}
		bool has_inf = false;
		for (i = 0; i < n; ++i)
			if (inp[i] == x) has_inf = true;
		if (has_inf)
		{
			cout << 1 << '\n';
			continue;
		}
		cout << 2 << '\n';
	}

	return 0;
}

