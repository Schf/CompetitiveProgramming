#include <bits/stdc++.h>
#define DEBUG 1

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define trav(a, x) for (auto & a : x)
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair <int, int> pii;
#define f first
#define s second
#define mp(x) make_pair (x)

typedef vector <int> vi;
#define pb(x) push_back (x)

#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

#define EXIT ddprintf ("\nT.E. %lf\n", 1.0 * clock () / CLOCKS_PER_SEC); exit (0)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

int main ()
{
    FASTIO;
    ll i, j;
    ll A, B, X;
    scanf ("%lld %lld %lld", &A, &B, &X);
    ddprintf ("%lld %lld %lld\n", A, B, X);
    for (i = 1; i < 10; i++)
    {
        j = pow (10, i);
        if (A*j + B*i > X)
            break;
    }
    ddprintf ("%lld\n", i);
    X -= B*i;
    if (X/A > 1000000000LL)
        printf ("1000000000\n");
    else if (X/A < 0)
        printf ("0\n");
    else
        printf ("%lld\n", X/A);


    EXIT;
}
