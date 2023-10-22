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
	ll i, j, n, x, y;
	cin >> n >> x >> y;
	vector <vector <ll>> graph (n);
	for (i = 1; i < n; ++i)
		graph[i].push_back (i - 1),
		graph[i - 1].push_back (i);
	graph[x - 1].push_back (y - 1);
	graph[y - 1].push_back (x - 1);
	vector <vector <ll>> viz (n, vector <ll> (n, INF));
	vector <ll> freq (n, 0);
	for (i = 0; i < n; ++i)
	{
		queue <ll> dfs;
		dfs.push (i);
		viz[i][i] = 0;
		while (!dfs.empty ())
		{
			ll cur = dfs.front ();
			dfs.pop ();
			trav (v, graph[cur])
				if (viz[i][v] > viz[i][cur] + 1)
					viz[i][v] = viz[i][cur] + 1,
					dfs.push (v);
		}
	}
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			++freq[viz[i][j]];
	for (i = 1; i < n; ++i)
		cout << freq[i] << '\n';

	return 0;
}


