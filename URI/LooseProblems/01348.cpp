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
	if (viz[tgt]) return viz[tgt];
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

		// input
		vector <pair <ll, ll>> inp;
		inp.reserve (2*c);
		for (i = 0; i < 2*c; ++i)
		{
			pair <ll, ll> temp;
			cin >> temp.f >> temp.s;
			if (temp.f == 0) swap (temp.f, temp.s);
			if (temp.f == 0) continue;
			if (temp.s == 0) temp.s = temp.f;
			--temp.f, --temp.s;
			temp.f <<= 1;
			temp.s <<= 1;
			if (i&1) ++temp.f, ++temp.s;
			inp.push_back (temp);
		}
		// "inp" guarda os pares logicos.
		// Para uma variavel qualquer Xi,
		//		i<<1 indica Xi,
		//		(i<<1)|1 indica ¬Xi.
		// Exemplo:
		//		Pra dupla (¬X1 | X3), "inp" guarda o par
		//		{(1 << 1) | 1, 3 << 1}, ou seja,
		//		{0011, 1010}.
		// Feito dessa forma para facilitar a inversao do valor logico.
		// Dado um valor qualquer inp[i].f, o inverso dele eh inp[i].f^1.
		
		// grafo
		vector <vector <ll>> dg (2*p), inv (2*p);
		trav (a, inp)
		{
			dg[a.f^1].push_back (a.s);
			inv[a.f].push_back (a.s^1);
			if (a.f != a.s)
				dg[a.s^1].push_back (a.f),
				inv[a.s].push_back (a.f^1);
		}
		
		// Kosaraju's
		vector <ll> viz (2*p, 0);
		vector <pair <ll, ll>> ord;
		ll curtime = 1;
		for (i = 0; i < 2*p; ++i)
		{
			if (viz[i]) continue;
			curtime = dfs (i, curtime, dg, viz);
			++curtime;
		}
		ord.reserve (2*p);
		for (i = 0; i < 2*p; ++i)
			ord.push_back ({viz[i], i});
		sort (ord.rbegin (), ord.rend ());
		viz = vector <ll> (2*p, 0);
		vector <vector <ll>> groups (1);
		vector <ll> point (2*p);
		trav (p, ord)
		{
			if (!viz[p.s])
				dfs (p.s, 1, inv, viz),
				groups.emplace_back ();
			groups[groups.size () - 1].push_back (p.s),
			point[p.s] = groups.size () - 1;
		}

		// 2SAT
		bool ans = true;
		for (i = 0; i < p; ++i)
			if (point[i << 1] == point[(i << 1) + 1])
				ans = false;
		vector <ll> vals (p, 0);
		for (i = groups.size () - 1; i >= 0; --i)
			for (j = 0; j < groups[i].size (); ++j)
				if (vals[groups[i][j]>>1] == 0)
					vals[vals[groups[i][j]>>1]] = (groups[i][j]&1) + 1;
		if (ans) cout << "yes\n";
		else cout << "no\n";

		cin >> c >> p;
	}

	return 0;
}

