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
	ll i, j, n;
	cin >> n;
	while (cin >> n)
	{
		string s;
		cin >> s;
		n = s.size ();
		for (i = 0; i < s.size () - 1; ++i)
			if (s[i] == '>')
				break;
		for (j = n - 1; j > 0; --j)
			if (s[j] == '<')
				break;
		cout << min (i, (ll)s.size () - j - 1) << '\n';
	}

	return 0;
}

