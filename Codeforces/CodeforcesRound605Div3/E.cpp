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
    vector <ll> inp (n), ans (n, INF);
    trav (a, inp) cin >> a;
    vector <vector <ll>> graph (n);
    for (i = 0; i < n; ++i)
    {
        if ((i + inp[i] < n && (inp[i]%2 != inp[i + inp[i]]%2)) ||
                (i - inp[i] >= 0 && (inp[i]%2 != inp[i - inp[i]]%2)))
            ans[i] = 1;
        if (i + inp[i] < n) graph[i + inp[i]].push_back (i);
        if (i - inp[i] >= 0) graph[i - inp[i]].push_back (i);
    }
    queue <ll> bfs;
    for (i = 0; i < n; ++i)
        if (ans[i] == 1) bfs.push (i);
    while (!bfs.empty ())
    {
        ll cur = bfs.front ();
        bfs.pop ();
        trav (v, graph[cur])
            if (ans[v] > ans[cur] + 1)
                ans[v] = ans[cur] + 1,
                bfs.push (v);
    }
    trav (a, ans) if (a == INF) a = -1;
    trav (a, ans) cout << a << ' ';
    cout << '\n';

	return 0;
}

