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
	cout << inp[1] - inp[0] << ' ' << inp[n - 1] - inp[0] << '\n';
	for (i = 1; i < n - 1; ++i)
		cout << min (inp[i] - inp[i - 1], inp[i + 1] - inp[i]) << ' ' <<
				max (inp[i] - inp[0], inp[n - 1] - inp[i]) << '\n';
	cout << inp[n - 1] - inp[n - 2] << ' ' << inp[n - 1] - inp[0] << '\n';

	return 0;
}

