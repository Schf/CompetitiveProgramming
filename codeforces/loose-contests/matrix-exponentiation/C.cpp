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

vector <vector <ll>>
operator * (vector <vector <ll>> & op, vector <vector <ll>> & mt)
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
	ll i, j, n;
	cin >> n;
	vector <vector <ll>> dp = {{0, 1}, {1, 1}}, mult = {{0, 1}, {1, 1}};
	while (n > 0)
	{
		if (n & 1) dp = dp * mult;
		mult = mult * mult;
		n /= 2;
	}
	cout << dp[0][0] << '\n';

	return 0;
}

