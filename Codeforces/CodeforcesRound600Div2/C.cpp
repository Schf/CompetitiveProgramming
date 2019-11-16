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
    int i, j, k;
    int n, m, sum;
    scanf ("%d %d", &n, &m);
    vi A (n);
    trav (a, A)
        scanf ("%d", &a);
    sort (all (A));
    for (i = 1; i <= A.size (); i++)
    {
        sum = 0;
        for (j = 0, k = 1; j < i; j++, j % m == 0 ? k++ : k)
            sum += A[i - 1 - j] * k;
        if (i == 1)
            printf ("%d", sum);
        else
            printf (" %d", sum);
    }
    printf ("\n");


    end:
    ddprintf ("Time elapsed %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}