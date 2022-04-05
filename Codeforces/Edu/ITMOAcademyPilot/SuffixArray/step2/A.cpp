#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;
#define f first
#define s second
#define mp(x, y) make_pair (x, y)

typedef long long ll;

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+5+7; // UPDATE

int main ()
{
	cin.sync_with_stdio (0);
	int i, j, n;

	string s;
	cin >> s;
	s.push_back (0);
	n = s.size ();
	vector <ll> v (n), c (n), r (n), t (n);
	iota (v.begin (), v.end (), 0);
	sort (v.begin (), v.end (),
			[&] (auto a, auto b) {return s[a] < s[b];});
	for (i = 1, r[v[0]] = 0; i < n; ++i)
		r[v[i]] = r[v[i - 1]] + (s[v[i]] != s[v[i - 1]]);
	// cout << s << endl;
	// for (auto a : v) cout << a << ' ';
	// cout << "| ";
	// for (auto a : r) cout << a << ' ';
	// cout << '\n';
	for (ll k = 1; r[v[n - 1]] < n - 1; k <<= 1)
	{
		fill (t.begin(), t.end(), 0);
		for (i = 0; i < n; ++i)
			t[r[i]+1]++;
		for (i = 2; i < n; ++i)
			t[i] += t[i - 1];
		
		for (i = 0; i < n; ++i)
			c[t[r[(v[i]-k+n)%n]]++] = (v[i] - k + n)%n;
		v = c;
		for (i = 1, t[v[0]] = 0; i < n; ++i)
			t[v[i]] = t[v[i - 1]] + ((r[v[i]] != r[v[i - 1]]) ||
					(r[(v[i]+k)%n] != r[(v[i-1]+k)%n]));
		r = t;
	}
	// for (auto a : v) cout << a << ' ';
	// cout << '\n';

	return 0;
}
