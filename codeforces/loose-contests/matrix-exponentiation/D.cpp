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

typedef vector <ll> vll;
typedef vector <vll> mll;

mll graph;

mll operator * (mll & op, mll & mt)
{
	auto aux = op;
	trav (v, aux) v.assign (v.size (), 0);
	for (ll i = 0; i < op.size (); ++i)
		for (ll j = 0; j < mt[0].size (); ++j)
			for (ll k = 0; k < op[0].size (); ++k)
				aux[i][j] += op[i][k] * mt[k][j],
				aux[i][j] %= MOD;
	return aux;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, k;
	cin >> n >> m >> k;
	graph.resize (n);
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].push_back (b);
	}
	mll dp (n, vll (n, 0)), mult (n, vll (n, 0));
	for (i = 0; i < n; ++i)
		for (j = 0, dp[i][i] = 1; j < graph[i].size (); ++j)
			mult[i][graph[i][j]] = 1;
	while (k > 0)
	{
		if (k & 1) dp = dp * mult;
		mult = mult * mult;
		k /= 2;
	}
	ll ans = 0;
	trav (v, dp)
		trav (a, v)
			ans += a,
			ans %= MOD;
	cout << ans << '\n';

	return 0;
}

