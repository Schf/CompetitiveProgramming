#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;

#define rep(i, a, b) for (i = (a); i < (b); i++)
#define trav(a, x) for (auto & a : x)
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair <int, int> pii;
#define f first
#define s second
#define mp(x, y) make_pair (x, y)

typedef vector <int> vi;
#define pb(x) push_back (x)

#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

int main ()
{
    FASTIO;
    int i, j, N, n1, n2, mn, mx, cur;
    scanf ("%d", &N);
    vector <vi> gi (N), p (2), g (N - 1);
    vi c(N - 1, -1), can (N - 1, 1);
    int cls = 0;
    for (i = 0; scanf ("%d %d", &n1, &n2) != EOF; i++)
    {
        n1--; n2--;
        gi[n1].pb (i);
        gi[n2].pb (i);
        g[i].pb (n1);
        g[i].pb (n2);
    }
    for (i = 0; i < sz (g); i++)
    {
        vi aux = {g[i][0], g[i][1]}; int k;
        g[i].clear ();
        for (k = 0; k < 2; k++)
            for (j = 0; j < sz (gi[aux[k]]); j++)
                if (gi[aux[k]][j] != i)
                    g[i].pb (gi[aux[k]][j]);
    }

    for (i = 0; i < sz (g); i++)
    {
        ddprintf ("%d: ", i);
        trav (a, g[i])
            ddprintf ("%d ", a);
        ddprintf ("-\n");
    }
    ddprintf ("--\n");
    for (i = 0; i < sz (c); i++)
        ddprintf ("%d: %d -\n", i, c[i]);
    ddprintf ("--\n");
    for (int I = 0; I < sz (c); I++)
    {
        if (c[I] != -1)
            continue;
        p[0].clear ();
        p[0].pb (I);
        for (i = 0; true; i = (i + 1) % 2)
        {
            p[(i + 1)%2].clear ();
            ddprintf ("p[i%%2]: ");
            trav (a, p[i%2])
                ddprintf ("%d ", a);
            ddprintf ("\n");
            while (sz (p[i%2]))
            {
                cur = p[i%2].back ();
                ddprintf ("\t%d: ", cur);
                p[i%2].pop_back ();
                for (j = 0; j < cls; j++)
                    can[j] = 1;
                for (j = 0; j < sz (g[cur]); j++)
                {
                    ddprintf ("<%d, %d> ", g[cur][j], c[g[cur][j]]);
                    if (c[g[cur][j]] == -1)
                        p[(i + 1)%2].pb (g[cur][j]);
                    else
                        can[c[g[cur][j]]] = 0;
                }
                ddprintf ("\n");
                for (j = 0; can[j] == 0; j++);
                while (j >= cls) cls++;
                c[cur] = j;
            }
            if (sz (p[(i + 1)%2]) == 0)
                break;
        }
    }
    ddprintf ("\n----------------------\n");
    printf ("%d\n", cls);
    rep (i, 0, sz(c))
        printf ("%d\n", c[i] + 1);


    return 0;
}
