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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		vector <string> alg (n + 1);
		trav (s, alg)
			s.resize (100, 'a');
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < inp[i]; ++j)
				alg[i + 1][j] = alg[i][j];
			alg[i + 1][inp[i]] = (((alg[i][inp[i]] - 'a') + 1) % 26) + 'a';
		}
		trav (s, alg) cout << s << '\n';
	}


	return 0;
}

