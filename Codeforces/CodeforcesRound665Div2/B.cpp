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
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		vector <ll> A (3), B (3);
		trav (a, A) cin >> a;
		trav (a, B) cin >> a;
		cout << 2*min (A[2], B[1]) -
				2*max (0LL, A[1] - max (0LL, B[1] - A[2]) - B[0]) << '\n';
	}


	return 0;
}

