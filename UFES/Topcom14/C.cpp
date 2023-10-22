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
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		string s;
		cin >> s;
		if (s.size () == 1) cout << 1 << s << '\n';
		else
		{
			for (i = 0, n = 1; i < s.size () - 1; ++i)
			{
				if (s[i] != s[i + 1]) cout << n << s[i], n = 1;
				else ++n;
			}
			if (s[s.size () - 2] != s[s.size () - 1]) cout << 1 << s[s.size () - 1];
			else cout << n << s[s.size () - 1];
			cout << '\n';
		}
	}

	return 0;
}

