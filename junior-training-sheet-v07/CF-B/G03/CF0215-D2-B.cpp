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
	ll i, j, n, r1 = 0, p1 = 0, p2 = INF;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> j, r1 = max (r1, j);
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> j, p1 = max (p1, j);
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> j, p2 = min (p2, j);
	ll A, B;
	cin >> A >> B;
	printf ("%.9f\n", sqrt (B*p1*r1*r1/(double)(A*p2 + B*p1)));

	return 0;
}

