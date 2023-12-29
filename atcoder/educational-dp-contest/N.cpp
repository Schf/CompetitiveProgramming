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

int main ()
{
    FASTIO;
    ll i, j, n, mn, sum = 0;
    cin >> n;
    vll A (n);
    mll dp (n, vll (n));
    trav (a, A)
        cin >> a;
    for (int l = n - 1; l >= 0; --l)
    {
        for (int r = l; r < n; ++r)
        {
            if (l == r) dp[l][r] = 0;
            else
            {
                dp[l][r] = INF;
                for (i = l, sum = 0; i <= r; sum += A[i++]);
                for (i = l; i <= r - 1; ++i)
                    dp[l][r] = min (dp[l][r], dp[l][i] + dp[i + 1][r] + sum);
            }
        }
    }
    dd trav (v, dp)
    {
        trav (a, v)
            printf ("% 4lld", a);
        printf ("\n");
    }
    printf ("%lld\n", dp[0][n - 1]);

    return 0;
}

