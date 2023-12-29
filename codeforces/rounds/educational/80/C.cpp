#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 1
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

mll dp;

ll mod_sum (ll a, ll b)
{
    a += b;
    if (a >= MOD) a -= MOD;
    else if (a < 0) a += MOD;
    return a;
}

int main ()
{
    FASTIO;
    int i, j, n, m;
    cin >> n >> m;
    dp = mll (2*m + 1, vll (n + 1));
    for (i = 1; i <= n; ++i)
        dp[0][i] = 1;
    for (i = 1; i <= 2*m; ++i)
        for (j = 1; j <= n; ++j)
            dp[i][j] = mod_sum (dp[i - 1][j], dp[i][j - 1]);
    cout << dp[2*m][n] << '\n';

    return 0;
}


