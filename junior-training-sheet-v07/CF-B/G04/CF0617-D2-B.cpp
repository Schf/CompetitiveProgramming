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
	vector <ll> inp (n), alg;
	trav (a, inp) cin >> a;
	ll cnt = 1, ans = 1;
	for (i = 0; i < n; ++i)
		if (inp[i]) break;
	if (i >= n) ans = 0;
	for (; i < n; ++i)
		if (inp[i]) alg.push_back (cnt), cnt = 1;
		else ++cnt;
	alg.push_back (cnt);
	for (i = 0; i < alg.size () - 1; ++i)
		ans *= alg[i];
	cout << ans << '\n';
		

	return 0;
}

