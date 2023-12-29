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
	ll i, j, n, k, p, q, r;
	cin >> n >> k;
	vll A (n), C (n);
	trav (a, A) cin >> a;
	trav (a, C) cin >> a;
	cin >> p >> q >> r;
	mll dp = {A};
	dp[0].push_back (1);
	dp[0].push_back (n);
	dp[0].push_back (n*n);
	mll mult (dp[0].size (), vll (dp[0].size (), 0));
	for (i = 0; i < n; ++i)
		mult[i + 1][i] = 1,
		mult[i][n - 1] = C[n - i - 1];
	mult[n][n - 1] = p;
	mult[n + 1][n - 1] = q;
	mult[n + 2][n - 1] = r;
	mult[n][n] = 1;
	mult[n][n + 1] = 1;
	mult[n + 1][n + 1] = 1;
	mult[n][n + 2] = 1;
	mult[n + 1][n + 2] = 2;
	mult[n + 2][n + 2] = 1;
	while (k)
	{
		if (k&1) dp = dp*mult;
		mult = mult*mult;
		k /= 2;
	}
	cout << dp[0][0] << '\n';

	return 0;
}

