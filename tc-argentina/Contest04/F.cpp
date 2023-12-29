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

vector <ll> prim (MAXN, 1), seg (MAXN, 1), terc (MAXN, 1);
ll n, x, y, c;

ll Test (ll t)
{
	ll i, j;
	ll quad = prim[t];
	if (t - (n - x + 1) >= 0)
		quad -= seg[t - (n - x + 1)];
	if (t - (n - y + 1) >= 0)
		quad -= seg[t - (n - y + 1)];
	if (t - x >= 0)
		quad -= seg[t - x];
	if (t - y >= 0)
		quad -= seg[t - y];
	if (t - (n - x + 1) - (n - y + 1) >= 0)
		quad += terc[t - (n - x + 1) - (n - y + 1)];
	if (t - (n - x + 1) - y >= 0)
		quad += terc[t - (n - x + 1) - y];
	if (t - x - (n - y + 1) >= 0)
		quad += terc[t - x - (n - y + 1)];
	if (t - x - y >= 0)
		quad += terc[t - x - y];
	return quad;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j;
	cin >> n >> x >> y >> c;
	if (c == 1)
	{
		cout << "0\n";
		return 0;
	}
	for (i = 1; i < MAXN; ++i)
		prim[i] = prim[i - 1] + i*4,
		seg[i] = seg[i - 1] + 2*i + 1,
		terc[i] = terc[i - 1] + i + 1;
	ll ans = 0, step;
	for (step = MAXN/2; step > 0; step /= 2)
		while (Test (ans + step) < c) ans += step;
	cout << ans + 1 << '\n';

	return 0;
}

