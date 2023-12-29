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

ll dfs (ll tgt, ll time, vector <vector <ll>> & dg, vector <ll> & viz)
{
	if (viz[tgt]) return time;
	viz[tgt] = time;
	trav (v, dg[tgt])
		if (!viz[v])
			time = dfs (v, time, dg, viz);
	return viz[tgt] = ++time;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll c, p;
	cin >> c >> p;
	while (c || p)
	{
		ll i, j, n;
		vector <pair <ll, ll>> inp (2*c);
		for (i = 0; i < 2*c; ++i)
		{
			cin >> inp[i].f >> inp[i].s;
			inp[i].f = 2 * (inp[i].f - 1);
			inp[i].s = 2 * (inp[i].s - 1);
			if (i&1) ++inp[i].f, ++inp[i].s;
		}
		printf ("1\n");
		vector <vector <ll>> dg (2*p), inv (2*p);
		trav (a, inp)
		{
			dg[a.f^1].push_back (a.s);
			dg[a.s^1].push_back (a.f);
			inv[a.f].push_back (a.s^1);
			inv[a.s].push_back (a.f^1);
		}
		printf ("2\n");
		vector <ll> viz (2*p, 0);
		vector <pair <ll, ll>> ord;
		ll curtime = 1;
		for (i = 0; i < 2*p; ++i)
		{
			if (viz[i]) continue;
			curtime = dfs (i, curtime, dg, viz);
			++curtime;
		}
		printf ("3\n");
		ord.reserve (2*p);
		for (i = 0; i < 2*p; ++i)
			ord.push_back ({viz[i], i});
		sort (ord.rbegin (), ord.rend ());
		viz = vector <ll> (2*p, 0);
		vector <vector <ll>> groups (1);
		vector <ll> point (2*p);
		printf ("4\n");
		trav (p, ord)
		{
			if (!viz[p.s])
				dfs (p.s, 1, inv, viz),
				groups.emplace_back ();
			groups[groups.size () - 1].push_back (p.s),
			point[p.s] = groups.size () - 1;
		}
		printf ("5\n");
		vector <ll> vals (p);
		for (i = groups.size () - 1; i >= 0; --i)
		{
			for (j = 0; j < groups[i].size (); ++j)
				if (vals[groups[i][j]>>1] == 0)
					vals[groups[i][j]>>1] = (groups[i][j]&1) + 1;
				else if (vals[groups[i][j]>>1] == 2 - (groups[i][j]&1))
					vals[groups[i][j]>>1] = 5;
			for (j = 0; j < groups[i].size (); ++j)
				if (0 < vals[groups[i][j]>>1] && vals[groups[i][j]>>1] < 3)
					vals[groups[i][j]>>1] += 2;
		}
		printf ("6\n");
		ll ans = true;
		for (i = 0; i < p; ++i)
			if (vals[i] > 4) ans = false;
		if (ans) cout << "Yes\n";
		else cout << "No\n";

		cin >> c >> p;
	}

	return 0;
}

