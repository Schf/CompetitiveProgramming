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
	ll i, j, n, a = 0, b = 0;
	cin >> n;
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	for (i = -1, j = n; j - i > 1;)
		if (a <= b) a += inp[++i];
		else b += inp[--j];
	cout << i + 1 << ' ' << n - j << '\n';

	return 0;
}

