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

vector <vector <int>> graph[2];
vector <int> parent[2];

void bfs (int gnum, int from, int & furthest, int & dist)
{
	parent[gnum].clear ();
	parent[gnum].resize (graph[gnum].size (), -1);
	vector <int> dists (graph[gnum].size (), INF);
	queue <int> q;
	q.push (from);
	dists[from] = 0;
	while (!q.empty ())
	{
		int cur = q.front ();
		q.pop ();
		trav (v, graph[gnum][cur])
			if (dists[v] > dists[cur] + 1)
			{
				q.push (v);
				dists[v] = dists[cur] + 1;
				parent[gnum][v] = cur;
			}
	}
	furthest = from;
	for (int i = 0; i < graph[gnum].size (); ++i)
		if (dists[furthest] < dists[i])
			furthest = i;
	dist = dists[furthest];
}

void bfs_dist (int gnum, int from, int tgt, int & dist)
{
	vector <int> dists (graph[gnum].size (), INF);
	queue <int> q;
	q.push (from);
	dists[from] = 0;
	while (!q.empty ())
	{
		int cur = q.front ();
		q.pop ();
		trav (v, graph[gnum][cur])
			if (dists[v] > dists[cur] + 1)
			{
				q.push (v);
				dists[v] = dists[cur] + 1;
			}
	}
	dist = dists[tgt];
}

int center (int gnum)
{
	int from, to, dist;
	bfs (gnum, 0, from, dist);
	bfs (gnum, from, to, dist);
	int center, candidate, ref_dist = dist; --dist;
	for (center = to; parent[gnum][center] >= 0 && dist > ref_dist/2;
			center = parent[gnum][center], --dist);
	if (!(ref_dist & 1)) return parent[gnum][center];
	int dist1, dist2;
	bfs_dist (gnum, center, 0, dist1);
	bfs_dist (gnum, parent[gnum][center], 0, dist2);
	if (dist1 > dist2) return center;
	else return parent[gnum][center];
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n, m;
		cin >> n >> m;
		graph[0].resize (n);
		graph[1].resize (m);
		for (i = 0; i < 2; ++i)
			for (j = 0; j < graph[i].size () - 1; ++j)
			{
				int a, b; cin >> a >> b; --a, --b;
				graph[i][a].push_back (b);
				graph[i][b].push_back (a);
			}
		cout << center (0) + 1 << ' ' << center (1) + 1 << "\n";
	}

	return 0;
}

