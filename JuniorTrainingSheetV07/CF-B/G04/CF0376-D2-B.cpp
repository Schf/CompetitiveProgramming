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
	cin >> n >> m;
	vector <vector <ll>> owe (n, vector <ll> (n)), own;
	own = owe;
	for (i = 0; i < m; ++i)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		owe[a][b] = c;
		own[b][a] = c;
	}
	vector <ll> order (n);
	for (ll count = 0; count < n; ++count)
	{
		iota (order.begin (), order.end (), 0);
		sort (order.begin (), order.end (), [&] (auto & a, auto & b)
		{
			ll av = 0, bv = 0;
			for (i = 0; i < n; ++i)
				av += own[a][i],
				bv += own[b][i];
			return av < bv;
		});
		for (i = 0; i < n; ++i)
		{
			ll cur = order[i];
			vector <ll> owners;
			for (j = 0; j < n; ++j)
				if (owe[cur][j])
					owners.push_back (j);
			trav (owner, owners)
			{
				vector <ll> sup_owners;
				for (j = 0; j < n; ++j)
					if (owe[owner][j])
						sup_owners.push_back (j);
				trav (sup_owner, sup_owners)
				{
					ll quit = min (owe[cur][owner], owe[owner][sup_owner]);
					owe[cur][owner] -= quit;
					own[owner][cur] -= quit;
					owe[owner][sup_owner] -= quit;
					own[sup_owner][owner] -= quit;
					if (cur != sup_owner)
						owe[cur][sup_owner] += quit,
						own[sup_owner][cur] += quit;
				}
			}
		}
	}
	ll ans = 0;
	trav (v, owe)
		trav (a, v)
			ans += a;
	cout << ans << '\n';

	return 0;
}

