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
		ll i, j, n;
		cin >> n;
		vector <pair <ll, ll>> inp (n);
		trav (p, inp) cin >> p.f >> p.s;
		bool can = (inp[0].f >= inp[0].s);
		for (i = 1; i < n; ++i)
			if (inp[i].f < inp[i].s || inp[i].f < inp[i - 1].f ||
					inp[i].s < inp[i - 1].s ||
					inp[i].f - inp[i - 1].f < inp[i].s - inp[i - 1].s)
				can = false;
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}
	

	return 0;
}

