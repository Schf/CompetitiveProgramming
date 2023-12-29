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

// 01:59:32

void mod_sum (ll & a, ll b)
{
    a += b;
    while (a >= MOD) a -= MOD;
    while (a < 0) a += MOD;
}

int main ()
{
    FASTIO;
    ll i, j, n, k;
    cin >> n >> k;
    vll A (n);
    mll dp (n, vll (k + 1));
    trav (a, A)
        cin >> a;
    for (i = 0; i <= A[0]; ++i)
        dp[0][i] = 1;
    for (i = 1; i < n; ++i)
    {
        vll sums (k + 1);
        for (j = 0; j <= k; ++j)
        {
            mod_sum (sums[j], dp[i - 1][j]);
            if (j + A[i] + 1 <= k)
                mod_sum (sums[j + A[i] + 1], MOD-dp[i - 1][j]);
        }
        mod_sum (dp[i][0], sums[0]);
        for (j = 1; j < sz(dp[i]); ++j)
        {
            mod_sum (sums[j], sums[j - 1]);
            mod_sum (dp[i][j], sums[j]);
        }
    }
    dd for (i = 0; i < sz (dp); ++i)
    {
        for (j = 0; j < min (30, sz (dp[i])); ++j)
            printf ("% 3lld", dp[i][j]);
        printf ("\n");
    }
    cout << dp[n - 1][k] << '\n';

    return 0;
}

