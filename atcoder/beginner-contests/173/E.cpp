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
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	sort (inp.begin (), inp.end ());
	ll p0, p1;
	for (p0 = p1 = n, i = 0; i < n; ++i)
	{
		if (inp[i] >= 0 && i < p0) p0 = i;
		if (inp[i] > 0 && i < p1) p1 = i;
	}
	

	return 0;
}

