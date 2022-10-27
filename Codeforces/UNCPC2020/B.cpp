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

vector <ll> suf_arr (string s)
{
	ll n = s.size();

	vector <ll> p(n);
	vector <ll> rank(2*n,-1);
	vector <ll> temp(2*n,-1);

	iota (p.begin (), p.end (), 0);
	sort(p.begin(),p.end(), [&] (auto i, auto j)
		{ return s[i] < s[j]; });

	rank[p[0]] = 0;
	for(ll i = 1; i < n; ++i) 
		rank[p[i]] = rank[p[i-1]] + (s[p[i]] != s[p[i - 1]]);

	for (ll i = 1; i < n; i *= 2)
	{
		sort (p.begin (), p.end (), [&] (auto it, auto jt)
		{
			if(rank[it] == rank[jt])
				return rank[it+i] < rank[jt+i];
			return rank[it] < rank[jt];
		});

		temp[p[0]] = 0;

		for (ll j = 1; j < n; ++j)
			temp[p[j]] = temp[p[j-1]] + (rank[p[j]] != rank[p[j-1]] ||
					rank[p[j] + i] != rank[p[j-1] + i]);

		copy (temp.begin (), temp.end (), rank.begin ());
	}
	return p;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string p, m;
	cin >> p >> m;
	vector <ll> pa, ma;
	pa = suf_arr (p);
	ma = suf_arr (m);
	/*for (i = 0; i < pa.size (); ++i)
	{
		for (j = pa[i]; j < p.size (); ++j)
			cout << p[j];
		cout << '\n';
	}
	for (i = 0; i < ma.size (); ++i)
	{
		for (j = ma[i]; j < m.size (); ++j)
			cout << m[j];
		cout << '\n';
	}*/
	string ps, ms;
	ps = p.substr (pa.back ());
	ms = m.substr (ma.back ());
	/*vector <ll> pa (p.size (), p.size () - 1),
			ma (m.size (), m.size () - 1);
	for (i = p.size () - 2; i >= 0; --i)
		if (p[i] >= p[pa[i + 1]]) pa[i] = i;
		else pa[i] = pa[i + 1];
	for (i = m.size () - 2; i >= 0; --i)
		if (m[i] >= m[ma[i + 1]]) ma[i] = i;
		else ma[i] = ma[i + 1];
	string ps, ms;
	ps += p[pa[0]];
	ms += m[ma[0]];
	for (i = 1; i < p.size (); ++i)
		if (pa[i] != pa[i - 1]) ps += p[pa[i]];
	for (i = 1; i < m.size (); ++i)
		if (ma[i] != ma[i - 1]) ms += m[ma[i]];*/
	cout << ps[0];
	for (i = 1; i < ps.size (); ++i)
		if (ps[i] >= ms[0]) cout << ps[i];
		else break;
	cout << ms << '\n';

	return 0;
}

