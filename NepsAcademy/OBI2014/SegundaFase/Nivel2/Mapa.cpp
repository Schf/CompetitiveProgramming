#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;
const ll LEVEL = 20;

int n;
vector <vector <pair <int, int>>> tree;
vector <int> qtd_abaixo, conexoes_abaixo, parent, total_conexoes;

void init_dfs (int tgt)
{
	for (int i = 0; i < tree[tgt].size (); ++i)
		if (tree[tgt][i].f == parent[tgt])
			parent[tgt] = i;
	qtd_abaixo[tgt] = 1;
	conexoes_abaixo[tgt] = 0;
	trav (v, tree[tgt])
		if (qtd_abaixo[v.f] < 0)
		{
			parent[v.f] = tgt;
			init_dfs (v.f);
			qtd_abaixo[tgt] += qtd_abaixo[v.f];
			if (v.s) conexoes_abaixo[tgt] += qtd_abaixo[v.f];
			else conexoes_abaixo[tgt] += conexoes_abaixo[v.f];
		}
}

void calc_dfs (int tgt)
{
	if (parent[tgt] == -1)
		total_conexoes[tgt] = conexoes_abaixo[tgt];
	else if (tree[tgt][parent[tgt]].s)
		total_conexoes[tgt] = n - qtd_abaixo[tgt] + conexoes_abaixo[tgt];
	else
		total_conexoes[tgt] = total_conexoes[tree[tgt][parent[tgt]].f];
	for (int i = 0; i < tree[tgt].size (); ++i)
		if (i != parent[tgt])
			calc_dfs (tree[tgt][i].f);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j;
		cin >> n;
		tree.resize (n, vector <pair <int, int>> ());
		qtd_abaixo.resize (n, -1);
		conexoes_abaixo.resize (n, -1);
		parent.resize (n, -1);
		total_conexoes.resize (n, -1);
		for (i = 0; i < n - 1; ++i)
		{
			int a, b, c; cin >> a >> b >> c; --a, --b;
			tree[a].push_back ({b, c});
			tree[b].push_back ({a, c});
		}
		init_dfs (0);
		calc_dfs (0);
		ll sum = 0;
		trav (a, total_conexoes) sum += a;
		cout << sum/2 << '\n';
	}

	return 0;
}


