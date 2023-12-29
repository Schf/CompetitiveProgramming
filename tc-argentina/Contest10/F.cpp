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

void mm (ll & a, ll b)
{
	a = (a*b)%MOD;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, k;

	vector <vector <ll>> comb (51, vector <ll> (51, 1));
  	for (i = 2; i < comb.size (); ++i)
    	for (j = 1; j < i; ++j)
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1],
			comb[i][j] %= MOD;
	
	cin >> n >> k; k /= 50;
	vector <ll> inp (n);
	trav (a, inp) cin >> a, a /= 50;
	sort (inp.begin (), inp.end ());
	if (inp[0] > k)
	{
		cout << "-1\n0\n";
		return 0;
	}
	if (n == 1)
	{
		cout << "1\n1\n";
		return 0;
	}
	if (inp[0] + inp[1] > k)
	{
		cout << "-1\n0\n";
		return 0;
	}
	if (inp.back () > k)
	{
		cout << "-1\n0\n";
		return 0;
	}
	ll ans1 = 0, ans2 = 1;
	vector <ll> l = inp, r;
	while (r.size () != inp.size ())
	{
		//trav (a, l) cout << a << ' ';
		//cout << "| ";
		//trav (a, r) cout << a << ' ';
		//cout << '\n';
		ll barco = 0, m = 0, g = 0;
		ll mo = lower_bound (l.begin (), l.end (), 2) - l.begin ();
		ll go = l.end () - lower_bound (l.begin (), l.end (), 2);
		if (r.size () && r[0] == 1)
			barco += l.back (),
			((l.back () == 2) && (g = 1)),
			((l.back () == 1) && (m = 1)),
			l.erase (--l.end ());
		else
			barco += l[0],
			((l[0] == 2) && (g = 1)),
			((l[0] == 1) && (m = 1)),
			l.erase (l.begin ());
		while (l.size () && barco + l[0] <= k)
			if (k - barco >= 2 && l.back () == 2)
				barco += l.back (),
				l.erase (--l.end ()),
				++g;
			else
				barco += l[0],
				((l[0] == 2) && (++g)),
				((l[0] == 1) && (++m)),
				l.erase (l.begin ());
		mm (ans2, comb[go][g]);
		mm (ans2, comb[mo][m]);
		for (i = 0; i < m; ++i)
			r.push_back (1);
		for (i = 0; i < g; ++i)
			r.push_back (2);
		sort (r.begin (), r.end ());
		++ans1;
		if (r.size () == inp.size ()) break;
		ll fat = lower_bound (r.begin (), r.end (), r[0] + 1) - 
				lower_bound (r.begin (), r.end (), r[0]);
		mm (ans2, comb[fat][1]);
		l.push_back (r[0]);
		sort (l.begin (), l.end ());
		r.erase (r.begin ());
		++ans1;
	}
	cout << ans1 << '\n' << ans2 << '\n';

	return 0;
}

