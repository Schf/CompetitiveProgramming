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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		string s, t;
		cin >> n >> s >> t;
		vector <ll> fs (26, 0), ft (26, 0);
		trav (c, s) ++fs[c - 'a'];
		trav (c, t) ++ft[c - 'a'];
		if (fs != ft)
		{
			cout << "NO\n";
			continue;
		}
		bool can = false;
		for (i = 0; i < 26 && !can; ++i)
			if (fs[i] > 1) can = true;
		if (can)
		{
			cout << "YES\n";
			continue;
		}
		ll is = 0, it = 0;
		for (i = 0; i < n; ++i)
			for (j = i + 1; j < n; ++j)
				is += (s[i] > s[j]),
				it += (t[i] > t[j]);
		if (is%2 == it%2)
		{
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}

	return 0;
}

