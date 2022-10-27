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

inline double calc (vector <int> & p1, vector <int> & p2)
{
	return hypot (p1[0] - p2[0], p1[1] - p2[1]) - p1[2] - p2[2];
}

/*inline bool inside (vector <int> & p1, vector <int> & p2)
{
	return hypot (p1[0] - p2[0], p1[1] - p2[1]) + p2[2] <= p1[2];
}*/

int main ()
{
	int tc = 1; scanf ("%d", &tc);
	while (tc--)
	{
		int i, j, n, w;
		scanf ("%d %d", &w, &n);
		vector <vector <int>> ps (n, vector <int> (3));
		trav (v, ps)
		{
			trav (a, v) scanf ("%d", &a);
			swap (v[0], v[1]);
		}
		sort (ps.begin (), ps.end ());
		double mn = INF;
		for (i = 0; i < ps.size (); ++i)
		{
			vector <int> aux = {ps[i][0], w, 0};
			if (ps[i][1] > w/2) aux[1] = 0;
			mn = min (mn, calc (ps[i], aux));
			for (j = i + 1; j < ps.size (); ++j)
				mn = min (mn, calc (ps[i], ps[j]));
		}
		mn = max (mn, 0.0);
		printf ("%.9lf\n", mn/2);
	}

	return 0;
}


