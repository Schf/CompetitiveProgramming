#pragma GCC optimize ("O2") // "Ofast" for REAL FAST
// #pragma GCC optimization ("unroll-loops")

// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;

#define rep(i, a, b) for (i = (a); i < (b); i++)
#define trav(a, x) for (auto & a : x)
#define all(x) (x).begin (), (x).end ()
#define rall(x) (x).rbegin (), (x).rend ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair <int, int> pii;
#define f first
#define s second
#define mp(x, y) make_pair (x, y)

typedef vector <int> vi;
#define pb(x) push_back (x)

#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7; // UPDATE

vi idl ('s' + 1, 0), pts ('s' + 1, 0), mm = {'r', 's', 'p'};

int main ()
{
    int i, j, n, k, sum = 0;
    string t;
    idl['r'] = 'p';
    idl['p'] = 's';
    idl['s'] = 'r';
    cin >> n >> k >> pts['r'] >> pts['s'] >> pts['p'] >> t;
    vi pls (n, 'a');
    sort (all (mm), [] (auto & a, auto & b) { return pts[a] > pts[b]; });
    for (int itt = 0; itt < 3; itt++)
    {
        for (i = 0; i < t.length (); i++)
        {
            if (idl[t[i]] == mm[itt])
            {
                if (!(k <= i && pls[i - k] == idl[t[i]]))
                {
                    pls[i] = idl[t[i]];
                    sum += pts[idl[t[i]]];
                }
            }
        }
    }
    trav (a, pls)
        ddcout << (char) a;
    ddcout << "\n";
    cout << sum << "\n";



    return 0;
}
