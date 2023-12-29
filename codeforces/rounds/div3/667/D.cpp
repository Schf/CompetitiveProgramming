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
		ll i, j, n, s;
		cin >> n >> s;
		ll mn = 0;
		vector <ll> dg;
		for (i = n; i > 0; i /= 10)
			dg.push_back (i%10);
		reverse (dg.begin (), dg.end ());
		ll cs = 0, cn = 0;
		trav (d, dg) cs += d;
		if (cs <= s)
		{
			cout << 0 << '\n';
			continue;
		}
		cs = 0;
		if (dg[0] >= s)
		{
			for (cn = 1; cn < n; cn *= 10);
		}
		else
		{
			bool ok = false;
			for (i = 0; i < dg.size (); ++i)
			{
				if (!ok && cs + dg[i] < s) cs += dg[i], cn *= 10, cn += dg[i];
				else if (!ok) ok = true, cn++, cn *= 10;
				else cn *= 10;
			}
		}
		cout << cn - n << '\n';
	}

	return 0;
}

