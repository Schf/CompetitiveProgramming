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
    int i, j;
    int N;
    ll fat = 0;
    double m = 0;
    scanf ("%d", &N);
    vector <pii> pt (N);
    trav (a, pt)
        scanf ("%d %d", &(a.fi), &(a.se));
    sort (all (pt));
    do
    {
        fat++;
        ddprintf ("%lf | ", m);
        trav (a, pt)
            ddprintf ("<%d, %d> ", a.fi, a.se);
        ddprintf ("\n");
        for (i = 1; i < pt.size (); i++)
            m += hypot (pt[i - 1].fi - pt[i].fi,
                    pt[i - 1].se - pt[i].se);
    } while (next_permutation (all (pt)));
    printf ("%.10lf\n", m / fat);
    return 0;
}