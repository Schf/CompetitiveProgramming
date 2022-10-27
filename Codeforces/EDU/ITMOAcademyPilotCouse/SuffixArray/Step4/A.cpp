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

vector <ll> suffix_array (string & s)
{
	s.push_back ('$'); // <---- -INF if numbers
	ll i, j, n = s.size ();
	vector <ll> p (n), c (n), r (n), t (n);
	iota (p.begin (), p.end (), 0);
	sort (p.begin (), p.end (), [&] (auto a, auto b)
		{ return s[a] < s[b]; });

	r[p[0]] = 0;
	for (i = 1; i < n; ++i)
		r[p[i]] = r[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);

	for (i = 1; i < n; i <<= 1)
	{
		trav (a, p) a = (a - i + n) % n;
		for (j = 0; j < n; ++j)
			++c[r[j]];
		for (j = 1; j < n; ++j)
			c[j] += c[j - 1];
		for (j = n - 1; j >= 0; --j)
			t[--c[r[p[j]]]] = p[j];
		c.assign (n, 0);
		copy (t.begin (), t.end (), p.begin ());

		t[p[0]] = 0;
		for (j = 1; j < n; ++j)
			t[p[j]] = t[p[j - 1]] + (t[p[j]] != t[p[j]] ||
					t[(p[j] + i) % n] != t[(p[j - 1] + i) % n]);
		
		copy (t.begin (), t.end (), r.begin ());
	}

	return p;
}

vector <ll> lcp_func (vector <ll> & sa, string & s)
{
	ll i, j, n = s.size ();
	vector <ll> r (n), g (n);
	for (i = 0; i < n; ++i)
		g[sa[i]] = i;

	ll k = 0;
	for (i = 0; i < n - 1; ++i)
	{
		while (s[i + k] == s[sa[g[i] - 1] + k]) ++k;
		r[g[i]] = k;
		k = max (k - 1, 0LL);
	}

	return r;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string s;
	cin >> s;
	auto sa = suffix_array (s);
	auto lcp = lcp_func (sa, s);
	n = s.size ();
	for (i = 0; i < n; ++i)
	{
		for (j = sa[i]; j < n; ++j) cout << s[j];
		cout << " | " << lcp[i] << '\n';
	}

	return 0;
}
