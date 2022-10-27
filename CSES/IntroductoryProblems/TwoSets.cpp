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
		cin >> n;
		if ((n*(n+1)/2)&1)
		{
			cout << "NO\n";
			continue;
		}
		vector <ll> a, b;
		if (n&1)
		{
			a.push_back (1);
			a.push_back (2);
			b.push_back (3);
			i = 4;
		}
		for (; i < n; i += 4)
		{
			if (i != 0)
				a.push_back (i);
			a.push_back (i + 3);
			b.push_back (i + 1);
			b.push_back (i + 2);
		}
		cout << "YES\n";
		cout << a.size () << '\n';
		trav (e, a) cout << e << ' ';
		cout << '\n';
		cout << b.size () << '\n';
		trav (e, b) cout << e << ' ';
		cout << '\n';
	}

	return 0;
}


