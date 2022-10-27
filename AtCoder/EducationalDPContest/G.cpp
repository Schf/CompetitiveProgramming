#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 0
#define dd if (DEBUG)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define rall(a) (a).rbegin (), (a).rend ()
#define sz(a) (int) (a).size ()
#define szl(a) (int) (a).length ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp(a, b) make_pair((a), (b))
typedef vector <int> vi;
typedef vector <vi> mi;
typedef vector <ll> vll;
typedef vector <vll> mll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

mi g;
vi viz;

int dfs (int i)
{
    if (viz[i] >= 0)
        return viz[i];
    trav (a, g[i])
        viz[i] = max (viz[i], dfs (a) + 1);
    return viz[i] = max (0, viz[i]);
}

int main ()
{
    FASTIO;
    int i, j, n, m, ax;
    cin >> n >> m;
    g = mi (n);
    viz = vi(n, -1);
    for (i = 0; i < m; i++)
    {
        cin >> j >> ax;
        g[j - 1].pb (ax - 1);
    }
    dd trav (v, g) {
        trav (a, v)
            cout << a << ' ';
        cout << '\n';}
    dd cout << endl;
    for (i = 0; i < n; i++)
    {
        if (viz[i] < 0)
        {
            dfs (i);
        }
    }
    for (i = 1, j = viz[0]; i < n; i++)
        j = max (j, viz[i]);
    cout << j << '\n';

    return 0;
}

