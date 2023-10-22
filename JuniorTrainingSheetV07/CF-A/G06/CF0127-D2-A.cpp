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
	ll i, j, n, k;
	cin >> n >> k;
	vector <pair <ll, ll>> inp (n);
	trav (p, inp) cin >> p.f >> p.s;
	double ans = 0;
	for (i = 1; i < n; ++i)
		ans += hypot (inp[i].f - inp[i - 1].f, inp[i].s - inp[i - 1].s);
	printf ("%.9lf\n", ans*k/50);

	return 0;
}

