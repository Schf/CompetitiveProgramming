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
	ll i, j, n, m, sum = 0;
	cin >> n >> m;
	vector <pair <ll, ll>> inp (m);
	for (i = 0; i < m; ++i)
		cin >> inp[i].f, inp[i].s = i, sum += inp[i].f;
	sort (inp.rbegin (), inp.rend ());
	bool can = sum >= n;
	multiset <ll> can_check;
	for (i = 0; i < m; ++i)
		inp[i].f = n - inp[i].f + 1;
	for (i = 0; can && i < m; ++i)
	{
		can_check.insert (inp[i].f);
		if (*(can_check.rbegin ()) < can_check.size ())
			can = false;
	}

	if (!can) cout << -1 << '\n';
	else
	{
		vector <pair <ll, ll>> out (m);
		out[m - 1].f = inp[m - 1].s, out[m - 1].s = inp[m - 1].f;
		ll pos = inp[m - 1].f;
		for (i = m - 2; i >= 0; --i)
			out[i].s = max (i + 1, min (inp[i].f, pos - (n - inp[i].f + 1))),
			out[i].f = inp[i].s, pos = out[i].s;
		bool can = true;
		for (i = 0; can && i < out.size () - 1; ++i)
			if (out[i].s + (n - inp[i].f + 1) < out[i + 1].s) can = false;
		if (can)
		{
			sort (out.begin (), out.end ());
			trav (p, out) cout << p.s << ' ';
			cout << '\n';
		}
		else cout << -1 << '\n';
	}

	return 0;
}

