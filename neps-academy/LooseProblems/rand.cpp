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
const ll MAXN = 2e+6+7;

inline int rand_n (int a, int b)
{
	return min (a, b) + rand () % (max (a, b) + 1 - min (a, b));
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j, n, m;
	cin >> n >> m;
	sq = sqrt (n) + 1;
	vector <ll> vec (n, 0), slp (sq, 0), off (sq, 0);
	int ord, tgt;
	while (cin >> ord >> tgt)
	{
		int buc = (--tgt)/sq;
		if (ord == 3)
		{
			cout << vec[tgt] + off[buc] + slp[buc]*(tgt - buc*sq) << '\n';
		}
		else if (ord == 2)
		{
			int val; cin >> val;
			for (i = tgt; i >= 0 && i >= buc*sq && val > 0; --i, --val)
				vec[i] += val;
			for (; buc >= 0 && val > sq; --buc, val -= sq)
				++slp[buc], off[buc] += val - sq;
			for (i = buc*sq; i > 0 && val > 0; --i, --val)
				vec[i] += val;
		}
		else
		{
			int val; cin >> val; ++buc;
			for (i = tgt; i < n && i < buc*sq && val > 0; ++i, --val)
				vec[i] += val;
			for (; buc < n/sq && val > sq; ++buc, val -= sq)
				slp[buc], off[buc] += val;
			for (i = buc*sq; i < n && val > 0; ++i, --val)
				vec[i] += val;
		}
		for (i = 0; i < n; ++i)
		{
			if (!(i%sq)) printf (" |");
			printf(" % 5lld", vec[tgt] + off[buc] + slp[buc]*(tgt - buc*sq));
		}
		printf ("\n");
	}

	return 0;
}


