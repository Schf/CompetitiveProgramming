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



int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	string s;
	cin >> s >> m;
	n = s.size ();
	vector <vector <ll>> alg ('z' + 1, vector <ll> (n + 1));
	for (i = 0; i < n; ++i)
		alg[s[i]][n - i] = n - i;
	for (i = 'a'; i <= 'z'; ++i)
	{
		for (j = 1; j <= n; ++j)
			alg[i][j] = max (alg[i][j], alg[i][j - 1]);
		//for (j = 0; j <= n; ++j) cout << alg[i][j] << ' ';
		//cout << '\n';
	}
	for (int mm = 0; mm < m; ++mm)
	{
		string cs;
		cin >> cs;
		ll cur_size = n;
		for (j = 0; j < cs.size (); ++j)
		{
			cur_size = alg[cs[j]][cur_size] - 1;
			if (cur_size < 0) break;
			//cout << j << ' ' << cs[j] << ' ' << cur_size << '\n';
		}
		if (j == 0) cout << "IMPOSSIBLE\n";
		else
		{
			for (i = 0; i < j; ++i)
				cout << cs[i];
			cout << '\n';
		}
	}

	return 0;
}

