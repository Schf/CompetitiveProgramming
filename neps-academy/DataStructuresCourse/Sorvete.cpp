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

#define DEBUG 0
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

int main ()
{
    FASTIO;
    int P, S, i, j, m = 0;
    scanf ("%d %d", &P, &S);
    if (!S)
    {
        printf ("\n");
        return 0;
    }
    vector <pii> ins (S);
    trav (a, ins)
    {
        scanf ("%d %d", &(a.fi), &(a.se));
        if (a.fi  > a.se)
        {
            a.fi -= a.se;
            a.se = a.fi + a.se;
            a.fi = -a.fi + a.se;
        }
    }
    sort (all (ins));
    trav (a, ins)
        ddprintf ("%d %d | ", a.fi, a.se);
    ddprintf ("\n");
    printf ("%d", ins[0].fi);
    m = ins[0].se;
    for (i = 1; i < ins.size (); i++)
    {
        if (m < ins[i].fi)
            printf (" %d\n%d", m, ins[i].fi);
        m = max (ins[i].se, m);
    }
    printf (" %d\n\n", m);
    return 0;
}