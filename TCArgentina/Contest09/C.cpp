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
	vector <ll> V (n), T (n), To (n);
	trav (a, V) cin >> a;
	trav (a, T) cin >> a;
	To = T;
	for (i = 1; i < n; ++i)
		V[i] += T[i - 1],
		T[i] += T[i - 1];
	vector <pair <ll, ll>> alg (n + 1, {0, 0});
	trav (a, V)
		j = lower_bound (T.begin (), T.end (), a) - T.begin (),
		++alg[j].f, alg[j].s += T[j] - a;
	for (i = 0, j = 1; i < n; ++i, ++j)
	{
		cout << To[i]*j - alg[i].s << ' ';
		j -= alg[i].f;
	}
	cout << '\n';

	return 0;
}

