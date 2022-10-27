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
	ll i, j, n;
	cin >> n;
	vector <vector <ll>> graph (n);
	for (i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (j = 0; j < n; ++j)
			if (s[j] == '1')
				graph[i].push_back (j);
	}
	queue <ll> bfs;
	vector <ll> dist (n, INF), parent (n, -1);
	dist[0] = 0;
	bfs.push (0);
	while (!bfs.empty ())
	{
		ll cur = bfs.front ();
		bfs.pop ();
		trav (a, graph[cur])
			if (dist[a] > dist[cur] + 1)
				dist[a] = dist[cur] + 1,
				parent[a] = cur,
				bfs.push (a);
	}
	bool can = true;
	for (i = 1; i < n; ++i)
		if (dist[i] >= INF) can = false;
	if (!can) cout << "impossible\n";
	else
	{
		set <pair <ll, ll>> out;
		for (i = 0; i < n; ++i)
			out.insert ({dist[i], i});
		for (auto itt = out.rbegin (); itt != out.rend (); ++itt)
			cout << itt->s << ' ';
		cout << '\n';
	}

	return 0;
}

