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
	ll i, j, n, m;
	cin >> n >> m;
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	sort (inp.begin (), inp.end ());
	vector <ll> alg (n, 0);
	for (i = 0; i < m; ++i)
		alg[i] = inp[i];
	for (i = m; i < n; ++i)
		alg[i] = inp[i] + alg[i - m];
	ll ans = 0;
	trav (a, alg)
		ans += a,
		cout << ans << ' ';
	cout << '\n';

	return 0;
}

