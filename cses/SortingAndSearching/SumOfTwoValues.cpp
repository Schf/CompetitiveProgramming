#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, x;
		cin >> n >> x;
		vector <pair <ll, ll>> inp (n);
		for (i = 0; i < n; ++i)
			cin >> inp[i].f, inp[i].s = i + 1;
		sort (inp.begin (), inp.end ());
		for (i = 0, j = n - 1; i < j;)
			if (inp[i].f + inp[j].f == x) break;
			else if (inp[i].f + inp[j].f < x) ++i;
			else if (inp[i].f + inp[j].f > x) --j;
		ll a = min (inp[i].s, inp[j].s), b = max (inp[i].s, inp[j].s);
		if (i < j) cout << a << ' ' << b << '\n';
		else cout << "IMPOSSIBLE\n";
	}

	return 0;
}


