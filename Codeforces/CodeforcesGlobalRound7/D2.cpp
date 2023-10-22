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
		a = b = a2 = b2 = "";
		for (i = 0; i < s.size ()/2; ++i)
			if (s[i] == s[s.size () - i - 1]) a += s[i], b += s[s.size () - i - 1];
			else break;
		if (i >= s.size ()/2)
		{
			if (s.size () & 1) a += s[s.size ()/2];
			for (i = 0; i < b.size ()/2; ++i)
				swap (b[i], b[b.size () - i - 1]);
			cout << a + b << '\n';
			continue;
		}
		for (j = i; j < s.size () - b.size (); ++j)
			a2 += s[j], b2 += s[s.size () - j - 1];
		for (i = 0; i < a2.size (); ++i)
			if (a2[i] != a2[a2.size () - i - 1])
				for (j = a2.size () - i, i = -1; a2.size () >= j; )
					a2.pop_back ();
		for (i = 0; i < b2.size (); ++i)
			if (b2[i] != b2[b2.size () - i - 1])
				for (j = b2.size () - i, i = -1; b2.size () >= j; )
					b2.pop_back ();
		for (i = 0; i < b.size ()/2; ++i)
			swap (b[i], b[b.size () - i - 1]);
		for (i = 0; i < b2.size ()/2; ++i)
			swap (b2[i], b2[b2.size () - i - 1]);
		if (a2.size () >= b2.size ()) cout << a + a2 + b << '\n';
		else cout << a + b2 + b << '\n';
	}

	return 0;
}


