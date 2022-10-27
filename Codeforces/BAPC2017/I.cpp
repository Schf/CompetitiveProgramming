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

ll p, q;
ll mat[101][101][2], bar[101][101];

ll solve (ll r, ll c, ll t)
{
	//cout << r << ' ' << c << ' ' << t << '\n';
	if (r <= 0 || c >= q) return 0;
	if (r == 1 && c == q - 1) return mat[r][c][t] = (2*(q&1))-1;
	if (mat[r][c][t] > -INF) return mat[r][c][t];
	ll i, j, ans = -INF;
	if (t == 0)
		for (i = c + 1; i <= q; ++i)
			ans = max (ans, (1-2*(c&1))*((i-c)&1)*(r&1) - solve (r, i, 1));
	else
		for (i = 0; i < r - 1; ++i)
			ans = max (ans, (1-2*((c&1)*((i+1)&1)))*((i+1)&1)*((q-c)&1) -
					solve (i + 1, c, 0));
	return mat[r][c][t] = ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> p >> q;
	for (i = 0; i < p; ++i)
		for (j = 0; j < q; ++j)
			bar[i][j] = (i + j) & 1 ? -1 : 1;
	for (i = 0; i < 101; ++i)
		for (j = 0; j < 101; ++j)
			mat[i][j][0] = mat[i][j][1] = -INF;
	cout << solve (p, 0, 0) << '\n';
	
	return 0;
}

