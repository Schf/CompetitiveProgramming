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

vector <ll> orig (3);

inline ll calc (vector <ll> & ord)
{
	return abs (ord[0] - orig[0])
			+ abs (ord[1] - orig[1])
			+ abs (ord[2] - orig[2]);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; cin >> tc;
	while (tc--)
	{
		int i, j, n;
		vector <ll> ord (3), tord (3);
		cin >> orig[0] >> orig[1] >> orig[2];
		ord[0] = ord[1] = ord[2] = 1;
		tord = ord;
		for (tord[0] = 1; tord[0] <= 2*orig[0]; ++tord[0])
			for (tord[1] = tord[0]; tord[1] <= 2*orig[1]; tord[1] += tord[0])
			{
				if (abs (orig[2] - (orig[2]/tord[1])*tord[1]) < 
						abs (orig[2] - (orig[2]/tord[1] + 1)*(tord[1])))
					tord[2] = max (tord[1], (orig[2]/tord[1])*tord[1]);
				else
					tord[2] = max (tord[1], (orig[2]/tord[1] + 1)*(tord[1]));
				if (calc (tord) < calc (ord))
					ord = tord;
			}
		cout << calc (ord) << '\n';
		trav (a, ord) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}


