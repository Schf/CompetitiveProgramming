#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n;
		vector <vector <int>> cart (3, vector <int> (3));
		trav (v, cart)
			trav (a, v)
				cin >> a;
		cin >> n;
		for (i = 0; i < n; ++i)
		{
			cin >> j;
			trav (v, cart)
				trav (a, v)
					if (a == j)
						a = -1;
		}
		bool ans = false;
		for (i = 0; i < cart.size (); ++i)
		{
			bool temp = true;
			for (j = 0; j < cart[i].size (); ++j)
			{
				if (cart[i][j] != -1)
					temp = false;
			}
			if (temp)
				ans = true;
		}
		for (j = 0; j < cart[0].size (); ++j)
		{
			bool temp = true;
			for (i = 0; i < cart.size (); ++i)
			{
				if (cart[i][j] != -1)
					temp = false;
			}
			if (temp)
				ans = true;
		}
		bool temp = true;
		for (i = 0; i < cart.size (); ++i)
		{
			if (cart[i][i] != -1)
				temp = false;
		}
		if (temp)
			ans = true;
		temp = true;
		for (i = 0; i < cart.size (); ++i)
			if (cart[i][cart.size () - i - 1] != -1)
				temp = false;
		if (temp)
			ans = true;
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}


