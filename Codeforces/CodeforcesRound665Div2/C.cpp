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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		if (is_sorted (inp.begin (), inp.end ()))
		{
			cout << "YES\n";
			continue;
		}
		ll mn = *min_element (inp.begin (), inp.end ());
		vector <ll> ord (n), grp (n, -1);
		iota (ord.begin (), ord.end (), 0);
		sort (ord.begin (), ord.end (), [&] (auto a, auto b)
			{ return inp[a] < inp[b]; });
		vector <pair <ll, ll>> rng (n);
		for (i = 0; i < n; ++i)
			if (i > 0 && inp[ord[i]] == inp[ord[i - 1]])
				rng[ord[i]] = rng[ord[i - 1]];
			else
			{
				rng[ord[i]].f = rng[ord[i]].s = i;
				for (j = i + 1; j < n && inp[ord[i]] == inp[ord[j]]; ++j)
					++rng[ord[i]].s;
			}
		bool ok = true;
		for (i = 0; i < n; ++i)
		{
			if (__gcd (mn, inp[i]) != mn)
			{
				if (i < rng[i].f || rng[i].s < i)
				{
					ok = false;
					cout << "NO\n";
					break;
				}
			}
		}
		
		if (ok) cout << "YES\n";
	}

	return 0;
}

