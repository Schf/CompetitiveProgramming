#include <bits/stdc++.h>

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& (a) : (x))
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair<int, int> pii;
#define f first
#define s second
#define mp(x) make_pair ((x))

typedef vector<int> vi;
#define pb(x) push_back ((x))

#define DEBUG 0
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

#define EXIT ddprintf ("Time elapsed %lf\n", 1.0 * clock() / CLOCKS_PER_SEC); exit (0)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

vector <pii> dl;
vector <vi> dp;
int m;

int ks (int t, int w)
{
    ddprintf ("t:%9d | w:%9d\n", t, w);
    if (t == sz (dl))
        return 0;
    if (dp[t][w+m] != -1)
        return dp[t][w+m];
    if (w <= 0)
    {
        dp[t][w+m] = ks(t + 1, w);
        ddprintf ("r:%9d |\n", dp[t][w+m]);
        return dp[t][w+m];
    }
    int v1 = ks(t + 1, w), v2 = ks(t + 1, w - dl[t].f) + dl[t].s;
    dp[t][w+m] = max (v1, v2);
    ddprintf ("r:%9d | 1:%9d | 2:%9d\n", dp[t][w+m], v1, v2);
    trav (a, dp)
    {
        trav (b, a)
            ddprintf ("%4d ", b);
        ddprintf ("\n");
    }
    return max (v1, v2);
}

int main ()
{
    int i, j;
    int N, T;
    m = 0;
    scanf ("%d %d", &N, &T);
    dl.resize (N);
    trav (a, dl)
    {
        scanf ("%d %d", &a.f, &a.s);
        m = max (m, a.f);
    }
    sort (all (dl));
    dp = vector <vi> (N + 1, vi (T + 1 + m, -1));
    trav (a, dl)
        ddprintf ("%d %d\n", a.f, a.s);
    trav (a, dp)
    {
        trav (b, a)
            ddprintf ("%d ", b);
        ddprintf ("\n");
    }
    ddprintf ("\n");
    printf ("%d\n", ks (0, T));
    

    EXIT;
}