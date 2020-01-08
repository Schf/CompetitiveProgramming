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
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
    FASTIO;
    int i, j, k, n;
    cin >> n;
    vector <vi> ac (n, vi (3)), dp (n, vi (3));
    trav (v, ac)
        trav (a, v)
            cin >> a;
    for (j = 0; j < 3; j++)
        dp[0][j] += ac[0][j];
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                if (j == k) continue;
                dp[i][j] = max (dp[i][j], dp[i - 1][k]);
            }
            dp[i][j] += ac[i][j];
        }
    }
    cout << max (max (dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << "\n";

    return 0;
}

