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

int solve (vi & A, int bit)
{
    if (bit < 0) return 0;
    vi on, off;
    trav (a, A)
    {
        if ((a >> bit) & 1) on.pb (a);
        else off.pb (a);
    }
    dd printf ("On:");
    dd trav (a, on)
        printf ("% 3d", a);
    dd printf ("\nOff:");
    dd trav (a, off)
        printf ("% 3d", a);
    dd printf ("\n");
    if (!sz (on)) return solve (off, bit - 1);
    if (!sz (off)) return solve (on, bit - 1);
    return min (solve (on, bit - 1), solve (off, bit - 1)) + (1 << bit);
}

int main ()
{
    FASTIO;
    int i, j, n, x = 0, ax;
    cin >> n;
    vi A (n);
    trav (a, A)
        cin >> a;
    dd printf ("n:% 3d\nA:", n);
    dd trav (a, A)
        printf ("% 3d", a);
    dd printf ("\n\n");
    cout << solve (A, 30) << '\n';

    return 0;
}

