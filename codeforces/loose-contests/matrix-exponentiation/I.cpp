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
typedef vector <mll> vmll;

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

mll graph;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m, q;
	cin >> n >> m >> q;
	graph.resize (n, vll (n));
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
	}
	vmll pows (32, mll (n, vll (n, 0)));
	for (i = 0; i < graph.size (); ++i)
		pows[0][i][i] = 1;
	pows[1] = graph;
	for (i = 2; i < 32; ++i)
		pows[i] = pows[i - 1] * pows[i - 1];
	for (i = 0; i < q; ++i)
	{
		mll dp (1, vll (n));
		ll s, t, k;
		cin >> s >> t >> k; --s, --t;
		dp[0][s] = 1;
		for (j = 1; k > 0; ++j, k >>= 1)
		{
			if (k&1) dp = dp * pows[j];
		}
		cout << dp[0][t] << '\n';
	}


	return 0;
}

