#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 0
#define dd if (DEBUG)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define rall(a) (a).rbegin (), (a).rend ()
#define sz(a) (int) (a).size ()
#define szl(a) (int) (a).length ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp(a, b) make_pair((a), (b))
typedef vector <int> vi;
typedef vector <vi> mi;
typedef vector <ll> vll;
typedef vector <vll> mll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

// 01:09:20h

int main ()
{
    FASTIO;
    int i, j, n;
    cin >> n;
    vector <double> c (n);
    vector <vector <double> > dp (n + 7, vector <double> (n + 7));
    trav (a, c)
        cin >> a;
    dp[0][0] = 1;
    dp[0][1] = c[0];
    for (i = 1; i < n; i++)
    {
        dp[i][0] = 1;
        for (j = 1; j <= n && dp[i][j - 1] != 0; j++)
        {
            dp[i][j] = c[i]*dp[i - 1][j - 1] + (1 - c[i])*dp[i - 1][j];
        }
    }
    dd trav (v, dp) {
        trav (a, v)
            printf ("% 4.4lf ", a);
        printf ("\n");
    }
    dd cout << endl;
    printf ("%.10lf\n", dp[n - 1][(n + 1)/2]);

    return 0;
}

