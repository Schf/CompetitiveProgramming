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
    int n, ax;
    cin >> n;
    vi d (n + 1), r (n + 1), f;
    for (i = 1; i <= n; i++)
    {
        cin >> d[i];
        r[d[i]] = i;
    }
    for (i = 1; i <= n; i++)
        if (r[i] == 0)
            f.pb (i);
    for (i = 1; i <= n; i++)
    {
        if (d[i] != 0)
            continue;
        // trav (a, f)
        //     ddprintf ("%d ", a);
        // ddprintf ("\n");
        j = f[sz (f) - 1];
        if (i == j)
        {
            if (sz (f) > 1)
            {
                j = f[sz (f) - 2];
                f[sz (f) - 2] = f[sz (f) - 1];
            }
            else
            {
                j = -1;
            }
        }
        f.pop_back ();
        d[i] = j;
    }
    for (i = 1; i <= n; i++)
    {
        if (d[i] == -1)
        {
            for (j = 1; j <= n && r[j] != 0; j++);
            for (ax = 1; ax <= n && d[ax] != j; ax++)
            d[i] = j;
            d[ax] = i;
            break;
        }
    }
    // for (i = 1, j = n; true;)
    // {
    //     while (d[i] != 0 && i < n + 1) i++;
    //     while (r[j] != 0 && j > 0) j--;
    //     if (i >= n + 1 || j <= 0)
    //         break;
    //     trav (a, d)
    //         ddprintf ("%d ", a);
    //     ddprintf ("| ");
    //     trav (a, r)
    //         ddprintf ("%d ", a);
    //     ddprintf ("|| %d %d %d %d\n", i, j, d[i], r[j]);
    //     if (i == j)
    //     {
    //         while (r[--j] != 0);
    //         d[i] = j;
    //         r[j] = i;
    //         j = i--;
    //         ++j;
    //     }
    //     else
    //     {
    //         d[i] = j;
    //         r[j] = i;
    //     }
    // }
    // trav (a, d)
    //     ddprintf ("%d ", a);
    // ddprintf ("| ");
    // trav (a, r)
    //     ddprintf ("%d ", a);
    // ddprintf ("\n");
    printf ("%d", d[1]);
    for (i = 2; i < n + 1; i++)
        printf (" %d", d[i]);
    printf ("\n");

    return 0;
}
