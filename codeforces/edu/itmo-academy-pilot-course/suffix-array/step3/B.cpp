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

vector <ll> suffix_array (string s)
{
	ll i, j, n = s.size () + 1;
	vector <ll> p (n, n - 1), c (n), r (n), t (n);
	iota (p.begin () + 1, p.end (), 0);
	sort (p.begin () + 1, p.end (), [&] (auto a, auto b)
		{ return s[a] < s[b]; });
	
	r[p[0]] = 0;
	r[p[1]] = 1;
	for (i = 2; i < n; ++i)
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
			t[p[j]] = t[p[j - 1]] + (r[p[j]] != r[p[j - 1]] ||
					r[(p[j] + i) % n] != r[(p[j - 1] + i) % n]);

		copy (t.begin (), t.end (), r.begin ());
	}

	p.erase (p.begin ());
	return p;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, q;
	string s;
	cin >> s >> q;
	n = s.size ();
	vector <ll> sa = suffix_array (s);
	for (ll qq = 0; qq < q; ++qq)
	{
		string t;
		cin >> t;
		ll l = 0, r;
		for (i = n/2; i > 0; i /= 2)
			while (l + i < n && s.substr (sa[l + i], t.size ()) < t)
				l += i;
		r = (l += (s.substr (sa[l], t.size ()) != t));
		for (i = (n - l)/2; i > 0; i /= 2)
			while (r + i < n && s.substr (sa[r + i], t.size ()) <= t)
				r += i;
		cout << r - l + 1 - (s.substr (sa[l], t.size ()) != t) << '\n';
	}

	return 0;
}

