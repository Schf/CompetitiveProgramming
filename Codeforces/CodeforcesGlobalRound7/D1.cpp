#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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

bool pal (string s)
{
	bool ans = true;
	for (int i = 0; i < s.size ()/2; ++i)
		if (s[i] != s[s.size () - i - 1])
		{
			ans = false;
			break;
		}
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		string s, a, b, a2, b2;
		cin >> s;
		a = b = "";
		for (i = 0; i < s.size (); ++i)
			for (j = i; j < s.size (); ++j)
			{
				a = "";
				for (int k = 0; k < i; ++k) a += s[k];
				for (int k = j; k < s.size (); ++k) a += s[k];
				cout << a << '\n';
				if (pal (s) && b.size () < a.size ()) b = a;
			}
		cout << b << '\n';
		cout << pal ("a") << '\n';
	}

	return 0;
}


