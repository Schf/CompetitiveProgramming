#pragma GCC optimize ("O2") // "Ofast" for REAL FAST
// #pragma GCC optimization ("unroll-loops")

// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;

#define rep(i, a, b) for (i = (a); i < (b); i++)
#define trav(a, x) for (auto & a : x)
#define all(x) (x).begin (), (x).end ()
#define rall(x) (x).rbegin (), (x).rend ()
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
const ll   MAXN  =  1e+6+7; // UPDATE

int main ()
{
    int i, j;
    int N, u, v, a, b;
    scanf ("%d %d %d", &N, &u, &v);
    vector <vi> t (N), l (2);
    vi viz (N, 0);
    while (scanf ("%d %d", &a, &b) == 2)
    {
        t[a].pb (b);
        t[b].pb (a);
    }
    l[0].pb (v);
    for (i = 0; true; i++)
    {
        l[(i+1)%2].clear ();
        trav (p, l[i%2])
        {
            trav (a, t[p])
            {
                if (a == u)
                    break;
                if (!viz[a])
                {
                    l[(i+1)%2].pb (a);
                    viz[a] = 1;
                }
            }
        }
        if (sz (l[(i+1)%2]) == 2)
            break;
    }
    printf ("%d\n", i);

    return 0;
}
