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

void transpose (vector <string> & mat)
{
	vector <string> out (mat[0].size ());
	trav (s, out) s.resize (mat.size ());
	for (ll i = 0; i < mat.size (); ++i)
		for (ll j = 0; j < mat[0].size (); ++j)
			out[j][i] = mat[i][j];
	mat = out;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	if (n >= 4 && m >= 4)
	{
		cout << "-1\n";
		return 0;
	}
	if (n > m) transpose (inp), swap (n, m);
	if (n == 1)
	{
		cout << "0\n";
		return 0;
	}
	vector <vector <ll>> alg (n - 1, vector <ll> (m - 1));
	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < m; ++j)
			alg[i][j] = inp[i][j] - '0',
			alg[i][j] += inp[i + 1][j] - '0',
			alg[i][j] += inp[i][j + 1] - '0',
			alg[i][j] += inp[i + 1][j + 1] - '0',
			alg[i][j] = alg[i][j]%2;
	ll ans = 0;
	if (n == 1)
	{
		for (i = 0; i < m - 1; ++i)
			if (alg[0][i] && alg[0][i + 1]) ++i;
			else if (!alg[0][i] &&  alg[0][i + 1]) ++ans;
			else if ( alg[0][i] && !alg[0][i + 1]) ;
			else ++ans, ++i;
	}
	else
	{
		for (i = 0; i < m - 1; ++i)
		{
			ll a = alg[0][i] + alg[1][i], b = alg[0][i + 1] = alg[1][i + 1];
			if (a == 2 && b == 2) ++i;
			else if (a == 2 && b == 1) ;
			else if (a == 2 && b == 0) ;
			else if (a == 1 && b == 2) 
			else if (a == 1 && b == 1)
			else if (a == 1 && b == 0)
			else if (a == 0 && b == 2) ++ans;
			else if (a == 0 && b == 1)
			else
		}
	}

	return 0;
}

