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
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i = 0, j, n;
		string s;
		cin >> s;
		vector <ll> cc ('Z' + 1, 0);
		trav (c, s) ++cc[c];
		ll oddchar = -1;
		for (i = 'A'; i <= 'Z'; ++i)
			if ((cc[i] & 1) && oddchar == -1) oddchar = i;
			else if ((cc[i] & 1) && oddchar > 0) oddchar = -2;
		if (oddchar == -2)
		{
			cout << "NO SOLUTION\n";
			continue;
		}
		for (i = 'A'; i <= 'Z'; ++i)
			for (j = 0; j < cc[i]/2; ++j)
				cout << (char) i;
		if (oddchar != -1) cout << (char) oddchar;
		for (i = 'Z'; i >= 'A'; --i)
			for (j = 0; j < cc[i]/2; ++j)
				cout << (char) i;
		cout << '\n';
	}

	return 0;
}


