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
#define mkp(x) make_pair ((x))

typedef vector<int> vi;
#define pb(x) push_back ((x))

#define DEBUG 1
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

#define ddprintfv(v) if (DEBUG) { trav (a, v) cout << a << " "; cout << "\n"; }

#define EXIT ddprintf ("Time elapsed %lf\n", 1.0 * clock() / CLOCKS_PER_SEC); exit (0)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

int main ()
{
    int i, j, t;
    int N, K;
    scanf ("%d %d", &N, &K);
    vector <ll> H (N + 2);
    vector <vector <ll> > dp (N + 2, vector <ll> (N + 2, INF));
    dp[0][0] = 0;
    for (i = 0; i != N; i++)
        scanf ("%lld", &H[i + 1]);
    for (i = 0; i < N + 1; i++)
        for (j = 0; j < min (i + 1, K + 1); j++)
            for (t = 0; t < j + 1; t++)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i - t][j - t] + max(0LL, H[i + 1] - H[i - t]));
                ddprintf ("i:%d | j:%d | t:%d | ", i, j, t);
                ddprintf ("dp[%d][%d]:%lld | ", i + 1, j, dp[i + 1][j]);
                ddprintf ("dp[%d][%d]:%lld | ", i - t, j - t, dp[i - t][j - t]);
                ddprintf ("H[%d] - H[%d]:%lld | ", i + 1, i - t, H[i + 1] - H[i - t]);
                ddprintf ("H[%d]:%lld | H[%d]:%lld\n", i + 1, H[i + 1], i - t, H[i - t]);
                if (DEBUG)
                trav (a, dp)
                {
                    trav (b, a)
                        ddprintf ("%21lld", b);
                    ddprintf ("\n");
                }
                ddprintf ("\n");
            }
    printf ("%lld\n", dp[N + 1][K]);

    EXIT;
}