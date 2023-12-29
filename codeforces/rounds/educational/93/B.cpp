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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		string s;
		cin >> s;
		vector <ll> points;
		j = 1 - (s[0] == '1');
		for (i = 1; i < s.size (); ++i)
			if (s[i] == '0' && s[i - 1] == '1')
				points.push_back (i - j);
			else if (s[i] == '1' && s[i - 1] == '0')
				j = i;
		if (s.back () == '1') points.push_back (i - j);
		sort (points.rbegin (), points.rend ());
		ll ans = 0;
		for (i = 0; i < points.size (); ++i)
			if (i%2 == 0) ans += points[i];
		cout << ans << '\n';

	}

	return 0;
}

