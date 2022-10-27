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
	ll tc;
	cin >> tc;
	for (ll tcc = 1; tcc <= tc; ++tcc)
	{
		cout << "Case #" << tcc << ": ";
		ll i, j, r, c;
		cin >> r >> c;
		vector <vector <ll>> mp (r, vector <ll> (c, 0)), prevmp;
		prevmp = mp;
		trav (v, mp)
			trav (a, v)
				cin >> a;
		ll ans = 0;
		while (prevmp != mp)
		{
			ll cur = 0;
			prevmp = mp;
			vector <pair <ll, ll>> take;
			for (i = 0; i < r; ++i)
				for (j = 0; j < c; ++j)
				{
					cur += mp[i][j];
					ll med = 0, count = 0;
					for (ll k = i + 1; k < r; ++k)
						if (mp[k][j] > 0)
						{
							med += mp[k][j], ++count;
							break;
						}
					for (ll k = i - 1; k >= 0; --k)
						if (mp[k][j] > 0)
						{
							med += mp[k][j], ++count;
							break;
						}
					for (ll k = j + 1; k < c; ++k)
						if (mp[i][k] > 0)
						{
							med += mp[i][k], ++count;
							break;
						}
					for (ll k = j - 1; k >= 0; --k)
						if (mp[i][k] > 0)
						{
							med += mp[i][k], ++count;
							break;
						}
					if (count > 0 && (double)med/count > mp[i][j])
						take.push_back ({i, j});
				}
			trav (p, take)
				mp[p.f][p.s] = 0;
			ans += cur;
		}
		cout << ans << '\n';
	}

	return 0;
}

