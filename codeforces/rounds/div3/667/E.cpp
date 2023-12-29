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
		ll i, j, n, k;
		cin >> n >> k;
		map <ll, ll> line;
		for (i = 0; i < n; ++i)
			cin >> j, line[j]++;
		for (i = 0; i < n; ++i)
			cin >> j;
		map <ll, ll> pref, mx;
		auto cx = line.begin ();
		ll cs = 0;
		trav (p, line)
		{
			while (p.f > cx->f + k) pref[cx->f] = cs, cs -= cx->s, ++cx;
			cs += p.s;
		}
		pref[cx->f] = cs;
		mx = pref;
		for (auto itt = mx.rbegin (); itt != mx.rend (); ++itt)
		{
			if (itt == mx.rbegin ()) ++itt;
			auto nxt = itt;
			--nxt;
			itt->s = max (itt->s, nxt->s);
		}
		//trav (p, line) cout << p.f << ' ' << p.s << " | ";
		//cout << '\n';
		//trav (p, pref) cout << p.f << ' ' << p.s << " | ";
		//cout << '\n';
		//trav (p, mx) cout << p.f << ' ' << p.s << " | ";
		//cout << '\n';
		ll ans = 0;
		for (auto itt = pref.begin (); itt != pref.end (); ++itt)
			if (mx.upper_bound (itt->f + k) != mx.end ())
				ans = max (ans, itt->s + mx.upper_bound (itt->f + k)->s);
			else ans = max (ans, itt->s);
		map <ll, ll> pref2;
		cx = line.begin ();
		cs = 0;
		trav (p, line)
		{
			while (p.f > cx->f + 2*k) pref2[cx->f] = cs, cs -= cx->s, ++cx;
			cs += p.s;
		}
		pref2[cx->f] = cs;
		trav (p, pref2)
			ans = max (ans, p.s);
		cout << ans << '\n';
	}

	return 0;
}

