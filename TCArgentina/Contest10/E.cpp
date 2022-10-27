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
	ll i, j, n, k, x;
	cin >> n >> k >> x;
	vector <pair <ll, ll>> inp (n);
	for (i = 0; i < n; ++i)
		cin >> inp[i].f, inp[i].s = i;
	sort (inp.begin (), inp.end ());
	ll f0 = n, s0 = n;
	for (i = 0; i < n; ++i)
	{
		if (f0 > i && inp[i].f >= 0) f0 = i;
		if (s0 > i && inp[i].f > 0)
		{
			s0 = i;
			break;
		}
	}
	if (s0 - f0 > k)
	{
		sort (inp.begin (), inp.end (), [] (auto & a, auto & b)
			{ return a.s < b.s; });
		trav (p, inp) cout << p.f << ' ';
		cout << '\n';
		return 0;
	}
	if (f0 == s0 && f0 == 0 && inp[0].f >= k*x)
	{
		inp[0].f -= k*x;
		sort (inp.begin (), inp.end (), [] (auto & a, auto & b)
			{ return a.s < b.s; });
		trav (p, inp) cout << p.f << ' ';
		cout << '\n';
		return 0;
	}
	if (f0 == s0 && f0 == n && abs (inp[n - 1].f) >= k*x)
	{
		inp[n - 1].f += k*x;
		sort (inp.begin (), inp.end (), [] (auto & a, auto & b)
			{ return a.s < b.s; });
		trav (p, inp) cout << p.f << ' ';
		cout << '\n';
		return 0;
	}
	if (!(f0&1))
	{
		if (s0 - f0 > 0)
			--k, inp[f0++].f -= x;
		else if (f0 == n || (f0 > 0 && abs (inp[f0 - 1].f) < inp[f0].f))
		{
			ll fat = min (abs (inp[f0 - 1].f)/x + 1, k);
			k -= fat;
			inp[f0 - 1].f += fat*x;
			if (inp[f0 - 1].f > 0) s0 = --f0;
		}
		else
		{
			ll fat = min (inp[f0].f/x + 1, k);
			k -= fat;
			inp[f0].f -= fat*x;
			if (inp[f0].f < 0) s0 = ++f0;
		}
	}
	for (i = f0; i < s0; ++i)
		--k, inp[i].f += x;
	sort (inp.begin (), inp.end (), [] (auto & a, auto & b) { return a.s < b.s; });
	set <pair <ll, ll>> alg;
	trav (p, inp) alg.insert ({abs(p.f), p.s});
	while (k-- > 0)
	{
		auto cur = *alg.begin ();
		alg.erase (alg.begin ());
		cur.f += x;
		inp[cur.s].f = (inp[cur.s].f/abs (inp[cur.s].f))*cur.f;
		alg.insert (cur);
	}
	trav (p, inp) cout << p.f << ' ';
	cout << '\n';

	return 0;
}

