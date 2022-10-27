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
	ll i, j, n, t;
	cin >> n;
	vector <ll> inp (n), pp (2, 0);
	trav (a, inp) cin >> a;
	for (i = t = 0, j = n - 1; i <= j; ++t)
		if (inp[i] > inp[j]) pp[t&1] += inp[i++];
		else pp[t&1] += inp[j--];
	cout << pp[0] << ' ' << pp[1] << '\n';

	return 0;
}

