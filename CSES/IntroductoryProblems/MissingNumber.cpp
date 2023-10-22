#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"
 
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
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> A (n - 1);
		trav (a, A) cin >> a;
		sort (A.begin (), A.end ());
		for (i = 0; i < A.size (); ++i)
			if (i + 1 != A[i])
				break;
		cout << i + 1 << '\n';
	}
 
	return 0;
}

