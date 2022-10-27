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

vector <vector <int>> fd, bk;
vector <int> viz, swp, qtd;

int dfs (int tgt, int flag)
{
	swp.push_back (tgt);
	viz[tgt] = flag;
	int ans = 1;
	trav (a, fd[tgt])
		if (!viz[a])
		 	ans += dfs (a, flag);
	return ans;
}



int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n, m, k;
		cin >> n >> m >> k;
		fd.resize (n);
		bk.resize (n);
		viz.resize (n, 0);
		qtd.resize (n, 0);
		for (i = 0; i < m; ++i)
		{
			int a, b; cin >> a >> b; --a, --b;
			fd[a].push_back (b);
			fd[b].push_back (a);
		}
		for (i = 0; i < k; ++i)
		{
			int a, b; cin >> a >> b; --a, --b;
			bk[a].push_back (b);
			bk[b].push_back (a);
		}
		int cur = dfs (0, 1); --cur;
		trav (a, swp)
		{
			qtd[a] = cur;
			trav (b, fd[a])
				if (viz[a] == viz[b])
					--qtd[a];
			trav (b, bk[a])
				if (viz[a] == viz[b])
					--qtd[a];
		}
		for (i = 1; i < n; ++i)
		{
			if (viz[i]) continue;
			swp.clear ();
			cur = dfs (i, i + 1); --cur;
			trav (a, swp)
			{
				qtd[a] = cur;
				trav (b, fd[a])
					if (viz[a] == viz[b])
						--qtd[a];
				trav (b, bk[a])
					if (viz[a] == viz[b])
						--qtd[a];
			}
		}
		trav (a, qtd) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}


