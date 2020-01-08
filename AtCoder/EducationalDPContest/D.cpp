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
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
    FASTIO;
    int i, j, n, w;
    cin >> n >> w;
    vector <ll> V (n), W (n), dp (w + 7);
    for (i = 0; i < n; i++)
    {
        cin >> W[i];
        cin >> V[i];
    }
    for (i = 0; i < n; i++)
    {
        dd trav (a, dp)
            cout << a << " ";
        dd cout << "\n";
        for (j = sz (dp) - W[i] - 1; j >= 0; j--)
        {
            dp[j + W[i]] = max (dp[j + W[i]], dp[j] + V[i]);
        }
    }
    dd trav (a, dp)
        cout << a << " ";
    dd cout << "\n";
    cout << dp[w] << "\n";

    return 0;
}

