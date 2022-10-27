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
	vector <pair <ll, ll>> inp (n);
	trav (p, inp)
	{
		cin >> p.f >> p.s;
		if (p.f > p.s)
			swap (p.f, p.s);
	}
	vector <ll> ans;
	while (inp.size ())
	{
		ll cur = INF;
		trav (p, inp) cur = min (cur, p.s);
		ans.push_back (cur);
		for (auto itt = inp.begin (); itt != inp.end (); ++itt)
		{
			while (itt != inp.end () && itt->f <= cur)
				itt = inp.erase (itt);
			if (itt == inp.end ())
				break;
		}
	}
	cout << ans.size () << '\n';
	trav (a, ans) cout << a << ' ';
	cout << '\n';

	return 0;
}

