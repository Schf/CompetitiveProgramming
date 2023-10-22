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
	vector <pair <ll, ll>> inp;
	inp.reserve (n);
	pair <ll, ll> bgn, end, rot;
	cin >> bgn.f >> bgn.s >> end.f >> end.s;
	
	// Rotacoes e translacoes
	end.f -= bgn.f;
	end.s -= bgn.s;
	if (end.f < 0) rot.f = true, end.f *= -1;
	if (end.s < 0) rot.s = true, end.s *= -1;
	for (i = 0; i < n; ++i)
	{
		ll a, b;
		cin >> a >> b;
		a -= bgn.f;
		b -= bgn.s;
		if (rot.f) a *= -1;
		if (rot.s) b *= -1;
		if (0 <= a && a <= end.f && 0 <= b && b <= end.s)
			inp.emplace_back (a, b);
	}
	bgn.f = 0, bgn.s = 0;
	
	// Algoritmo
	n = inp.size ();
	sort (inp.begin (), inp.end ());
	multiset <ll> lis;
	trav (a, inp)
	{
		auto itt = lis.upper_bound (a.s);
		if (itt == lis.end ()) lis.insert (a.s);
		else lis.erase (itt), lis.insert (a.s);
	}
	cout << lis.size () << '\n';

	return 0;
}

