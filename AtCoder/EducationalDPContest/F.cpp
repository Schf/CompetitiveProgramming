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
    int i, j, n;
    string s, t;
    cin >> s >> t;
    mi dp (szl(s) + 7, vi (szl (t) + 7));
    for (i = 0; i <= szl (s); i++)
    {
        for (j = 0; j <= szl (t); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
        
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    dd for (i = 0; i <= szl (s); i++) {
        if (i <= 0)
            for (j = 1, cout << "  "; j <= szl (t); j++)
                cout << t[j - 1] << ' ';
        else
            for (j = 1, cout << s[i - 1] << ' '; j <= szl (t); j++)
                cout << dp[i][j] << ' ';
        cout << '\n';}
    dd cout << '\n';
    string out;
    for (i = szl (s), j = szl (t), n = dp[i][j]; n != 0;)
    {
        for (; j >= 0 && n == dp[i][j]; --j);
        ++j;
        dd printf ("%c %d ", t[j - 1], j);
        for (; i >= 0 && n == dp[i][j]; --i);
        ++i;
        dd printf ("%c %d\n", s[i - 1], i);
        out += s[i - 1];
        --i;
        n = dp[i][j];
    }
    for (i = szl (out) - 1; i >= 0; i--)
        cout << out [i];
    cout << '\n';

    return 0;
}

