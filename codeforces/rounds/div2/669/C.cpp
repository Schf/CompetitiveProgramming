#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ll i, j, n, k;
	cin >> n;
	ll mxid = 0;
	for (i = 1; i < n; ++i)
	{
		cout << "? " << mxid + 1 << ' '  << i + 1 << endl;
		ll res;
		cin >> res;
	}

	return 0;
}

