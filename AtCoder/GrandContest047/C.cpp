#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 200003;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, ans;
	cin >> n;
	vector <ll> inp (n), suf (n);
	trav (a, inp) cin >> a;
	suf = inp;
	for (i = n - 2; i >= 0; --i)
		suf[i] += suf[i + 1];
	ans = 0;
	for (i = 0; i < n - 1; ++i)
		ans = (ans + inp[i]*suf[i + 1]%MOD)%MOD;
	cout << ans << '\n';

	return 0;
}

