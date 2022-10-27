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
	int i, j, n = s.size ();
	vector <ll> p (n), r (2*n,-1), t (2*n,-1);
	iota (p.begin (), p.end (), 0);
	sort (p.begin (), p.end (), [&] (auto a, auto b)
		{ return s[a] < s[b]; } );

	r[p[0]] = 0;
	for (i = 1; i < n; ++i)
		r[p[i]] = r[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
	
	for (i = 1; i < n; i <<= 1)
	{
		sort (p.begin (), p.end (), [&] (auto a, auto b)
		{
			if (r[a] == r[b]) return r[a + i] < r[b + i];
			return r[a] < r[b];
		});

		t[p[0]] = 0;
		for (j = 1; j < n; ++j)
			t[p[j]] = t[p[j - 1]] + (r[p[j]] != r[p[j - 1]] ||
					r[p[j] + i] != r[p[j - 1] + i]);

		copy (t.begin (), t.begin () + n, r.begin ());
	}
	return p;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string s;
	cin >> s;
	vector <ll> sufa = suffix_array (s);

	return 0;
}

