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

mll operator * (mll & op, mll & mt)
{
	auto aux = op;
	trav (v, aux) v.assign (v.size (), INFLL);
	for (ll i = 0; i < op.size (); ++i)
		for (ll j = 0; j < mt[0].size (); ++j)
			for (ll k = 0; k < op[0].size (); ++k)
				aux[i][j] = min (aux[i][j], op[i][k] + mt[k][j]),
				aux[i][j] = min (aux[i][j], INFLL);
	return aux;
}

mll graph;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, k;
	cin >> n >> m >> k;
	graph.resize (n, vll (n, INFLL));
	for (i = 0; i < m; ++i)
	{
		ll a, b, w;
		cin >> a >> b >> w;
		--a, --b;
		graph[a][b] = w;
	}

	mll dp (1, vll (n));
	while (k)
	{
		if (k&1) dp = dp * graph;
		graph = graph * graph;
		k /= 2;
	}
	ll ans = INFLL;
	trav (a, dp[0]) ans = min (ans, a);
	if (ans >= INFLL/2) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';

	return 0;
}

