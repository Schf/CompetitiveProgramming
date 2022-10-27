#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef int ll;

const ll MOD = 1e+9+7;
//const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ll i, j, n, k;
	double t1, t2;
	scanf ("%d %lf %lf %d", &n, &t1, &t2, &k);
	t1 = t1*(1 - ((double)k/100.0));
	vector <pair <double, ll>> ans (n);
	for (i = 0; i < n; ++i)
	{
		ll a, b;
		scanf ("%d %d", &a, &b);
		ans[i].f = max (a*t1 + b*t2, b*t1 + a*t2);
		ans[i].f *= -1;
		ans[i].s = i + 1;
	}
	sort (ans.begin (), ans.end ());
	trav (p, ans) printf ("%d %.2f\n", p.s, -p.f);

	return 0;
}

