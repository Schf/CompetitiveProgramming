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
	ll i, j, n;
	cin >> n;
	vector <vector <ll>> alg (MAXN);
	for (i = 0; i < n; ++i)
	{
		ll a;
		cin >> a;
		--a;
		alg[a].push_back (i);
	}
	vector <pair <ll, ll>> ans;
	for (i = 0; i < MAXN; ++i)
	{
		if (alg[i].size () == 1)
			ans.push_back ({i + 1, 0});
		else if (alg[i].size ())
		{
			ll px = alg[i][1] - alg[i][0];
			for (j = 2; j < alg[i].size (); ++j)
			{
				if (px != alg[i][j] - alg[i][j - 1])
					px = -1;
			}
			if (px > 0)
				ans.push_back ({i + 1, px});
		}
	}
	cout << ans.size () << '\n';
	trav (p, ans) cout << p.f << ' ' << p.s << '\n';

	return 0;
}

