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
		int i, j, n, m;
		cin >> n >> m;
		vector <int> num (n, -1);
		for (i = 0; i < m; ++i)
		{
			int pos, aux; cin >> pos >> aux; --pos;
			if (num[pos] >= 0 && num[pos] != aux) num[pos] = -2;
			else if (num[pos] == -1) num[pos] = aux;
		}
		if (n == 1)
		{
			if (num[0] == -2) cout << "-1\n";
			else if (num[0] == -1) cout << "0\n";
			else cout << num[0] << '\n';
		}
		else
		{
			for (i = 0; i < num.size (); ++i)
				if (num[i] == -2) break;
			if (num[0] == 0) i = num.size () - 1;
			if (i < num.size ())
			{
				cout << "-1\n";
				continue;
			}
			if (num[0] == -1) num[0] = 1;
			for (i = 1; i < num.size (); ++i)
				if (num[i] == -1) num[i] = 0;
			trav (a, num) cout << a;
			cout << '\n';
		}
	}

	return 0;
}


