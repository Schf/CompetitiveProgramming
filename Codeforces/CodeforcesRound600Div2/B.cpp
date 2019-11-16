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
#define fi first
#define se second
#define mkp(x) make_pair ((x))

typedef vector<int> vi;
#define pb(x) push_back ((x))

#define DEBUG 0
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

int main ()
{
    int i, j;
    int n, elems = 0;
    bool pos, neg;
    scanf ("%d", &n);
    set <int> tab;
    vi ent (n), days;
    ll st = 0;
    trav (a, ent)
        scanf ("%d", &a);
    trav (a, ent)
        ddprintf ("%d ", a);
    ddprintf ("\n");
    trav (a, ent)
    {
        if (DEBUG)
        {
            trav (b, tab)
                ddprintf ("%d ", b);
            ddprintf ("| %lld %d\n", st, a);
        }
        pos = tab.find (abs (a)) != tab.end ();
        neg = tab.find (-1 * abs (a)) != tab.end ();
        if (a > 0)
        {
            if (!pos && !neg)
            {
                st += a;
                tab.insert (a);
            }
            else if (pos && neg)
            {
                if (st != 0)
                {
                    printf ("-1\n");
                    goto end;
                }
                else
                {
                    tab.clear ();
                    tab.insert (a);
                    st += a;
                    days.pb (elems);
                    elems = 0;
                }
            }
            else
            {
                printf ("-1\n");
                goto end;
            }
        }
        if (a < 0)
        {
            if (!pos)
            {
                printf ("-1\n");
                goto end;
            }
            else
            {
                st += a;
                tab.insert (a);
            }
        }
        elems++;
    }
    if (DEBUG)
    {
        trav (a, tab)
            ddprintf ("%d ", a);
        ddprintf ("| %lld\n", st);
    }
    if (st != 0)
        printf ("-1\n");
    else
    {
        if (elems != 0)
            days.pb (elems);
        printf ("%d", sz (days));
        for (i = 0; i < sz (days); i++)
        {
            if (i == 0)
                printf ("\n%d", days[i]);
            else
                printf (" %d", days[i]);
        }
        printf ("\n");
    }


    end:
    ddprintf ("Time elapsed %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}