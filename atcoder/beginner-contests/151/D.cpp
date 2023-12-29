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
mi viz;

bool acc (int h, int w)
{
    if (h < 0 || sz (g) <= h) return false;
    if (w < 0 || sz (g[0]) <= w) return false;
    return g[h][w];
}

void dfs (int h, int w)
{
    if (!acc (h, w)) return;
    dd printf ("Enter % 3d % 3d, viz[% 3d][% 3d]:% 3d\n", h, w, h, w, viz[h][w]);
    if (acc (h, w - 1))
        if (viz[h][w] + 1 < viz[h][w - 1])
        {
            viz[h][w - 1] = viz[h][w] + 1;
            dfs (h, w - 1);
        }
    if (acc (h, w + 1))
        if (viz[h][w] + 1 < viz[h][w + 1])
        {
            viz[h][w + 1] = viz[h][w] + 1;
            dfs (h, w + 1);
        }
    if (acc (h - 1, w))
        if (viz[h][w] + 1 < viz[h - 1][w])
        {
            viz[h - 1][w] = viz[h][w] + 1;
            dfs (h - 1, w);
        }
    if (acc (h + 1, w))
        if (viz[h][w] + 1 < viz[h + 1][w])
        {
            viz[h + 1][w] = viz[h][w] + 1;
            dfs (h + 1, w);
        }
}

int main ()
{
    FASTIO;
    int i, j, n, h, w, mx, mn, k, l;
    string s;
    cin >> h >> w;
    getline (cin, s);
    g = mi (h, vi (w));
    viz = mi (h, vi (w));
    for (i = 0; i < h; ++i)
    {
        getline (cin, s);
        for (j = 0; j < szl (s); ++j)
        {
            if (s[j] == '.') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }
    dd trav (v, g)
    {
        trav (a, v)
            printf ("% 3d", a);
        printf ("\n");
    }
    dd printf ("-------------------------\n");

    mx = -1;
    for (i = 0; i < h; ++i)
    {
        for (j = 0; j < w; ++j)
        {
            trav (v, viz)
                trav (a, v)
                    a = INFi;
            viz[i][j] = 0;
            dfs (i, j);
            dd trav (v, viz)
            {
                trav (a, v)
                    printf ("% 3d", a);
                printf ("\n");
            }
            dd printf ("-------------------------\n");
            for (k = 0; k < h; ++k)
                for (l = 0; l < w; ++l)
                    if (acc (k, l) && viz[k][l] != INFi) mx = max (mx, viz[k][l]);
        }
    }
    cout << mx << '\n';

    return 0;
}


