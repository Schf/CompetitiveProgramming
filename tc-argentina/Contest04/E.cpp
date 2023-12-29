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
	vector <pair <ll, ll>> inp (n);
	trav (p, inp) cin >> p.s >> p.f;
	sort (inp.begin (), inp.end ());
	ll last = -INF, ans = 0;
	trav (p, inp)
		if (last < p.s)
			last = p.f, ++ans;
	cout << ans << '\n';

	return 0;
}

