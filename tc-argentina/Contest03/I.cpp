#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	vector <ll> fib = {1, 1};
	for (i = 2; i < MAXN; ++i)
		fib.push_back ((fib[i - 1] + fib[i - 2]) % MOD);
	cin >> n;
	cout << fib[n + 2] - 2 << '\n';

	return 0;
}

