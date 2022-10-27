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
	sort (inp.begin (), inp.end ());
	for (i = 1; i < n; ++i)
		if (inp[i] != inp[i - 1])
			break;
	for (j = n - 2; j >= 0; --j)
		if (inp[j] != inp[j + 1])
			break;
	cout << max (0LL, j - i + 1) << '\n';

	return 0;
}

