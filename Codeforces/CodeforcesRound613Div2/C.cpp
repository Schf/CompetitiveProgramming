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
    ll i, j, n, a, b, rt, ax, bx;
    cin >> n;
    vll f = {1};
    if (n < 4) cout << "1 " << n << '\n';
    else
    {
        for (i = 2; i*i < n; ++i)
        {
            for (j = 0; !(n%i); ++j, n /= i);
            if (j) f.pb (pow (i, j));
        }
        if (n > 1) f.pb (n);
        sort (rall (f));
        dd trav (a, f)
            printf ("% 3lld", a);
        dd printf ("\n");
        a = b = INF;
        for (i = 0; i < (1 << sz (f)); ++i)
        {
            ax = bx = 1;
            for (j = 0; j < sz (f); ++j)
            {
                if ((i >> j) & 1) ax *= f[j];
                else bx *= f[j];
            }
            if (max (ax, bx) < max (a, b))
            {
                a = ax;
                b = bx;
            }
        }
        cout << min (a, b) << ' ' << max (a, b) << '\n';
    }
    

    return 0;
}

