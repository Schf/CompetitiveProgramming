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

void getall (list <vector <ll>> & prc, vector <pair <ll, ll>> & out, ll id)
{
	auto itt = prc.begin ();
	ll last = -INF;
	while (itt != prc.end ())
	{
		if (last <= (*itt)[0])
		{
			last = (*itt)[1];
			out.push_back ({(*itt)[2], id});
			itt = prc.erase (itt);
		}
		else ++itt;
	}
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc;
	cin >> tc;
	for (ll tcc = 1; tcc <= tc; ++tcc)
	{
		ll i, j, n;
		cin >> n;
		vector <vector <ll>> inp (n, vector <ll> (3));
		vector <pair <ll, ll>> out;
		out.reserve (n);
		trav (v, inp) cin >> v[0] >> v[1];
		for (i = 0; i < n; ++i)
			inp[i][2] = i;
		sort (inp.begin (), inp.end ());
		list <vector <ll>> prc;
		trav (v, inp) prc.push_back (v);
		getall (prc, out, 1);
		getall (prc, out, 2);
		if (prc.size ()) cout << "Case #" << tcc << ": IMPOSSIBLE\n";
		else
		{
			sort (out.begin (), out.end ());
			string outstr;
			trav (p, out)
				if (p.s == 1) outstr += 'C';
				else outstr += 'J';
			cout << "Case #" << tcc << ": " << outstr << '\n';
		}
	}

	return 0;
}


