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
typedef vector <vll> vmll;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

// 00:22:00h

int main ()
{
    FASTIO;
    int i, j, n, k;
    cin >> n >> k;
    vi A (n), dp (2*k + 1);
    trav (a, A)
    {
        cin >> a;
        dp[a] = 1;
    }
    for (i = 0; i <= k; ++i)
    {
        trav (a, A)
        {
            if (!dp[i])
                dp[i + a] = 1;
        }
    }
    dd for (i = 0; i < sz (dp); ++i)
        printf ("% 3d", i);
    dd printf ("\n");
    dd trav (a, dp)
        printf ("% 3d", a);
    dd printf ("\n");
    if (dp[k]) cout << "First";
    else cout << "Second";
    cout << '\n';

    return 0;
}

