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
	cin.tie (0);
	int i, j, n;

	string s;
	cin >> s;
	n = s.size () + 1;
	vector <ll> v (n), r (n), t (n);
	iota (v.begin (), v.end (), 0);
	for (i = 0; i < n - 1; ++i)
		r[i] = s[i];
	r[n - 1] = 0;
	for (ll k = 1; r[v[n - 1]] != n - 1; k <<= 1)
	{
		auto cmp = [&] (auto a, auto b)
		{
			if (r[a] == r[b]) return r[(a+k)%n] < r[(b+k)%n];
			return r[a] < r[b];
		};
		sort (v.begin (), v.end (), cmp);
		t[v[0]] = 0;
		for (i = 1; i < n; ++i)
			t[v[i]] = t[v[i - 1]] + cmp (v[i - 1], v[i]);
		r = t;
	}
	for (auto a : v) cout << a << ' ';
	cout << '\n';

	return 0;
}
