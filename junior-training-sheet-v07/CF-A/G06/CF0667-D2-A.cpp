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
	ll i, j, n;
	double d, h, v, e;
	cin >> d >> h >> v >> e;
	if (d*d*e*3.14159265359/4 >= v) printf ("NO\n");
	else printf ("YES\n%.9lf\n", (d*d*h*3.14159265359/4)/(v - d*d*e*3.14159265359/4));

	return 0;
}

