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
	for (ll tcc = 1; tcc <= tc; ++tcc)
	{
		ll i, j, n;
		string s, out;
		cin >> s;
		for (i = 0; i < s[0] - '0'; ++i)
			out += '(';
		out += s[0];
		for (i = 1; i < s.size (); ++i)
		{
			if (s[i] > s[i - 1])
				for (j = 0; j < s[i] - s[i - 1]; ++j)
					out += '(';
			else if (s[i] < s[i - 1])
				for (j = 0; j < s[i - 1] - s[i]; ++j)
					out += ')';
			out += s[i];
		}
		for (i = 0; i < s[s.size () - 1] - '0'; ++i)
			out += ')';
		cout << "Case #" << tcc << ": " << out << '\n';
	}

	return 0;
}

