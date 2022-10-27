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
	ll i, j, n, m, a, b;
	cin >> n >> m >> a >> b;
	vector <pair <ll, ll>> inp (n);
	for (i = 0; i < n; ++i)
	{
		inp[i].s = i;
		ll l, h;
		cin >> l >> h;
		inp[i].f = l*a + h*b;
	}
	sort (inp.begin (), inp.end ());
	for (i = 0; i < n && m >= 0; m -= inp[i++].f);
	if (m < 0) --i;
	cout << i << '\n';
	for (j = 0; j < i; ++j)
		cout << inp[j].s + 1 << ' ';
	cout << '\n';

	return 0;
}

