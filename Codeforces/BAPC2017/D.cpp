#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m;
const ll nax = 1e5 + 5;
const ll INF = 1e18;
set <pair <ll, ll> > adj[nax];
ll parent[nax];
set <pair <ll,ll > > path;
vector <ll> ans;
bool visitado[nax];

void dfs (ll tgt)
{
	for (auto a : adj[tgt])
		if (!visitado[a.first])
			visitado[a.first] = 1,
			parent[a.first] = tgt,
			dfs (a.first);
}

void solve(){
	vector <ll> dist(n+1,INF);

	dist[1] = 0;
	parent[1] = -1;

	set < pair <ll, ll> > pq;
	pq.insert({0,1});

	 while (!pq.empty()){
		ll u = pq.begin()->second;
		pq.erase(pq.begin());
		for (auto a : adj[u]){
			ll v = a.first;
			ll w = a.second;
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.insert({dist[v], v});
			}
		}
	}

	ll i, j;
	for (i = 0; i < n; ++i)
		if (parent[i] >= 0)
			adj[i].erase (adj[i].upper_bound ({parent[i], -1LL}));

	memset (parent, -1, sizeof parent);
	memset (visitado, 0, sizeof visitado);
	visitado[0] = 1;
	dfs (0);

	if (!visitado[1]) cout << "impossible\n";
	else
	{
		vector <ll> out (1, 1);
		ll v = parent[1];
		while (v != -1)
			out.push_back (v), v = parent[v];
		cout << out.size ();
		for (i = out.size () - 1; i >= 0; --i)
			cout << ' ' << out[i];
		cout << '\n';
	}
}

int main(){
	
	cin >> n >> m;

	for(ll i=0;i<m;i++){
	ll u,v,d;
	cin >> u >> v >> d;
	adj[u].insert ({v,d});
	adj[v].insert ({u,d});
	}

	solve();

	return 0;
}

