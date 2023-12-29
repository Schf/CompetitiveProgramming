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
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n, q, t, f;
		char c;
		string s;
		cin >> s >> q;
		deque <char> dq;
		bool inv = false;
		trav (a, s) dq.push_back (a);
		for (int qq = 0; qq < q; ++qq)
		{
			cin >> t;
			if (t == 1) inv = !inv;
			else
			{
				cin >> f >> c;
				while (c < 'a' || 'z' < c) cin >> c;
				if ((f == 1 && !inv) || (f == 2 && inv)) dq.push_front (c);
				else dq.push_back (c);
			}
		}
		if (inv)
			for (auto itt = dq.rbegin (); itt != dq.rend (); ++itt)
				cout << *itt;
		else
			trav (a, dq)
				cout << a;
		cout << '\n';
	}

	return 0;
}


