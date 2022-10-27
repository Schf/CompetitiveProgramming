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
const ll MAXN = 1e+6+7;

vector <vector <int>> grafo;
vector <int> indc;

void LeArvore ()
{
	int n; cin >> n;
	grafo.resize (n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b; --a, --b;
		grafo[a].push_back (b);
		grafo[b].push_back (a);
	}
}

int dfs (int alvo)
{
	indc[alvo] = 1;
	for (auto viz : grafo[alvo])
		if (!indc[viz])
			indc[alvo] += dfs (viz);
	return indc[alvo];
}

int main ()
{
	int n;
	LeArvore ();
	n = grafo.size ();
	indc.resize (n, 0);
	dfs (0);
	int cur = 0;
	while (true)
	{
		int ir_para = -1;
		for (auto viz : grafo[cur])
			if (indc[viz] < indc[cur] && n/2 < indc[viz])
				ir_para = viz;
		if (ir_para == -1) break;
		for (auto viz : grafo[cur])
			if (indc[viz] < indc[cur] && n/2 < indc[viz] && indc[ir_para] < indc[viz])
				ir_para = viz;
		cur = ir_para;
	}
	// cur = centroid da arvore
	cout << cur + 1 << '\n';

	return 0;
}


