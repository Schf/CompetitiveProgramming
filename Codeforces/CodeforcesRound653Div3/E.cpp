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
	ll i, j, n, k;
	cin >> n >> k;
	vector <pair <ll, pair <ll, ll>>> inp (n);
	trav (p, inp) cin >> p.f >> p.s.f >> p.s.s;
	ll atot = 0, btot = 0;
	sort (inp.begin (), inp.end (), [&] (auto & a, auto & b)
	{
		ll amult = ((a.s.f + a.s.s == 0) ? INF : 3 - (a.s.f + a.s.s));
		ll bmult = ((b.s.f + b.s.s == 0) ? INF : 3 - (b.s.f + b.s.s));
		if (a.f*amult == b.f*bmult)
			return amult < bmult;
		return a.f*amult < b.f*bmult;
	});
	vector <pair <ll, ll>> avec, bvec;
	for (i = 0; i < n; ++i)
	{
		if (inp[i].s.f)
			if (inp[i].s.s) avec.emplace_back (inp[i].f, 1LL), bvec.emplace_back (inp[i].f, 1LL);
			else avec.emplace_back (inp[i].f, 0LL);
		else if (inp[i].s.s) bvec.emplace_back (inp[i].f, 0LL);
	}
	ll t = 0;
	for (i = j = 0; i < avec.size (); ++i)
		if (avec[i].s) ++j, t += avec[i].f;
	ll mem = j;
	for (i = 0; i < avec.size () && j < k; ++i)
		if (!avec[i].s) ++j, t += avec[i].f;
	j = mem;
	for (i = 0; i < bvec.size () && j < k; ++i)
		if (!bvec[i].s) ++j, t += bvec[i].f;
	if (avec.size () < k || bvec.size () < k) cout << -1 << '\n';
	else cout << t << '\n';

	return 0;
}

