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
	cin >> n;
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	sort (inp.rbegin (), inp.rend ());
	ll a = 0, b = 0;
	for (i = 0; i < n; ++i)
		if (i&1) b += inp[i];
		else a += inp[i];
	cout << a << ' ' << b << '\n';

	return 0;
}

