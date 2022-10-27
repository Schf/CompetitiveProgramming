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

int main ()
{
    int i, j;
    int C;
    string str;
    scanf ("%d", &C); getline (cin, str);
    while (C--)
    {
        vi qnt('U' + 1, 0);
        getline (cin, str);
        trav (a, str)
            if ('A' < a && a < 'Z')
                qnt[a]++;
        qnt['R'] = min (qnt['L'], qnt['R']);
        qnt['D'] = min (qnt['U'], qnt['D']);
        if (qnt['R'] > 0 && qnt['D'] > 0)
        {
            printf ("%d\n", 2*(qnt['R'] + qnt['D']));
            for (i = 0; i < qnt['R']; i++) printf ("R");
            for (i = 0; i < qnt['D']; i++) printf ("D");
            for (i = 0; i < qnt['R']; i++) printf ("L");
            for (i = 0; i < qnt['D']; i++) printf ("U");
            printf ("\n");
        }
        else if (qnt['R'] > 0)
            printf ("2\nRL\n");
        else if (qnt['D'] > 0)
            printf ("2\nDU\n");
        else
            printf ("0\n\n");
    }

    return 0;
}
