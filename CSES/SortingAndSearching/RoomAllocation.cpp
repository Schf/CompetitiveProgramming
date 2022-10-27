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
		ll i, j, n;
		cin >> n;
		vector <pair <pair <ll, ll>, ll>> inp (n);
		vector <ll> out (n);
		for (i = 0; i < n; ++i)
			cin >> inp[i].f.s >> inp[i].f.f, inp[i].s = i;
		sort (inp.begin (), inp.end ());
		set <pair <ll, ll>> qt;
		qt.insert ({inp[0].f.f, 1});
		out[inp[0].s] = 1;
		for (i = 1; i < n; ++i)
		{
			if (inp[i].f.s <= qt.begin ()->f)
			{
				out[inp[i].s] = qt.size () + 1;
				qt.insert ({inp[i].f.f, qt.size () + 1});
				continue;
			}
			auto itt = qt.upper_bound ({inp[i].f.s, 0});
			--itt;
			out[inp[i].s] = itt->s;
			qt.insert ({inp[i].f.f, itt->s});
			qt.erase (itt);
		}
		cout << qt.size () << '\n';
		trav (a, out) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}


