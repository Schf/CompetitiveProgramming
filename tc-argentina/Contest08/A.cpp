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
	ll i, j, n, m;
	cin >> n;
	vector <ll> inp;
	for (i = j = 0; i < n; ++i)
		cin >> m,
		inp.push_back (j + m),
		j += m;
	cin >> m;
	for (i = 0; i < m; ++i)
		cin >> n,
		cout << lower_bound (inp.begin (), inp.end (), n) - inp.begin () + 1 << '\n';

	return 0;
}

