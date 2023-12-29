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
	ll i, j, n, l;
	string s, t;
	cin >> s >> t;
	for (i = j = 0; i < s.size () && j < t.size (); ++j)
		if (s[i] == t[j]) ++i;
	l = j - 1;
	if (i < s.size ())
	{
		cout << "0\n";
		return 0;
	}
	for (i = s.size () - 1, j = t.size () - 1; i >= 0 && j >= 0; --j)
		if (s[i] == t[j]) --i;
	if (i >= 0)
	{
		cout << "0\n";
		return 0;
	}
	++j;
	//cout << j << ' ' << l << '\n';
	cout << max (j - l, 0LL) << '\n';

	return 0;
}

