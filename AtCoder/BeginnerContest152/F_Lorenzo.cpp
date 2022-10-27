#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b) ; ++i)
using namespace std;
#define inf 0x3f3f3f3f
int u,v, n;
vector<int> dist;
using graph = vector<vector<int>>;
graph g;
set<pair<int, int>> s;

main(){
    cin >> n;
    g = graph(n);
    dist = vector<int> (n, inf);
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m;
    cin >> m;
    rep(i, 0, m){
        cin >> u >> v;
        u--, v--;
        dist.assign(n, inf);
        queue<int> q;
        vector<int> parent(n, -1);
        parent[u] = u;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            for (auto a : g[x]){
                if (dist[a] == inf){
                    dist[a] = dist[x] + 1;
                    parent[a] = x;
                    q.push(a);
                }
            }
        }
        int x = v;
        while (parent[x] != x){
            if (!s.count({x, parent[x]}) and !s.count({parent[x], x}))
                s.insert({x, parent[x]});
            cout << x << ' ' << parent[x] << '\n';
            x = parent[x];
        }
    }
    long long ans = (1LL << (n - 1)) - (1LL << (n - 1 - s.size()));
    cout << ans << '\n';
}