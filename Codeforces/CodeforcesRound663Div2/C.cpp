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
	ll i, j, n;
	cin >> n;
	vector <ll> fact (n + 1), pow (n + 1);
	fact[0] = fact[1] = 1;
	for (i = 2; i <= n; ++i)
		fact[i] = (i*fact[i - 1])%MOD;
	pow[0] = 1;
	for (i = 1; i <= n; ++i)
		pow[i] = (2*pow[i - 1])%MOD;
	
	cout << (fact[n] - pow[n - 1] + MOD)%MOD<< '\n';

	return 0;
}

