#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& (a) : (x))
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mkp(x) make_pair ((x))

typedef vector<int> vi;
#define pb(x) push_back ((x))

#define DEBUG 1
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

int trig (int lvl, int pos, vi & old)
{
    if (!lvl)
        return old[old.size ()/2 - pos] % MOD;
    vi cur (old.size () + 1, 1);
    for (int i = 1; i < old.size (); i++)
    {
        cur[i] = (old[i] + old[i - 1]) % MOD;
        cur[i] %= MOD;
    }
    return trig (lvl-1, pos, cur);
}

int main ()
{
    int i, j;
    int X, Y;
    scanf ("%d %d", &X, &Y);
    if ((X + Y)%3 == 0)
    {
        if (min (X, Y) * 2 >= max (X, Y))
        {
            ll den = 1, div = 1;
            int n = (X+Y)/3, k = (n + 1)/2 - abs (X-Y)/2;
            ddprintf ("%d %d\n", n, k);
            vector <ll> N (n - max (k, n - k)), K (min (k, n - k));
            for (i = 0; i != N.size (); i++)
                N[i] = n - i;
            for (i = 0; i != K.size (); i++)
                K[i] = K.size () - i;
            trav (a, N)
                ddprintf ("%lld ", a);
            ddprintf ("\n");
            trav (a, K)
                ddprintf ("%lld ", a);
            ddprintf ("\n");
            trav (a, N)
                den = (den * a) % MOD;
            den %= MOD;
            ddprintf ("%lld\n", den);
            trav (a, K)
                div = (div * a) % MOD;
            div %= MOD;
            ddprintf ("%lld\n", div);
            printf ("%lld\n", (den/div) % MOD);
            goto end;
        }
    }
    printf ("0\n");
    end:
    ddprintf ("Time elapsed %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}