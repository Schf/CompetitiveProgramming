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
		vector <set <ll>> sets (1);
		for (i = 0; i < n; ++i)
		{
			ll aux;
			cin >> aux;
			for (j = 0; j < sets.size (); ++j)
				if (sets[j].find (aux) == sets[j].end ())
					break;
			if (j >= sets.size ()) sets.push_back (set <ll> ());
			sets[j].insert (aux);
		}
		ll ans = 0;
		trav (s, sets)
			ans += s.size () - 1;
		cout << ans << '\n';

		cin >> n;
	}

	return 0;
}


