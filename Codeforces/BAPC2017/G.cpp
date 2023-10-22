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
	ll i, j, n, m;
	cin >> m >> n;
	vector <vector <ll>> deve (m, vector <ll> (m, 0));
	for (i = 0; i < n; ++i)
	{
		ll a, b, p;
		cin >> a >> b >> p;
		--a, --b;
		deve[a][b] += p;
	}
	for (i = 0; i < m; ++i)
		for (j = 0; j < m; ++j)
			if (i == j) continue;
			else if (deve[i][j] > deve[j][i]) deve[i][j] -= deve[j][i], deve[j][i] = 0;
			else deve[j][i] -= deve[i][j], deve[i][j] = 0;
	

	return 0;
}

