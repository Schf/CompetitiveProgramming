#pragma GCC optimize ("O2") // "Ofast" for REAL FAST
// #pragma GCC optimization ("unroll-loops")

// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 0

using namespace std;

#define rep(i, a, b) for (i = (a); i < (b); i++)
#define trav(a, x) for (auto & a : x)
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0);

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
    //FASTIO;
    ll i, j;
    ll a, b, lst, sum;
    scanf ("%lld %lld\n", &a, &b);
    string l;
    getline (cin, l);
    ddcout << a << " " << b << "\n" << l << "\n";
    vi cs (26, 0); char c;
    while (scanf ("%c", &c) != EOF)
        if ('a' <= c && c <= 'z')
            cs[c - 'a'] = 1;
    trav (a, cs)
        ddcout << a << " ";
    ddcout << "\n";
    for (i = 0, lst = 0, sum = 0; i < l.length (); i++)
    {
        ddcout << l[i] << " " << cs[l[i] - 'a'] << " " << i << " " << lst << " " << i - lst << "\n";
        if (!cs[l[i] - 'a'])
        {
            sum += (i - lst)*(i - lst + 1)/2;
            lst = i + 1;
        }
    }
    sum += (i - lst)*(i - lst + 1)/2;

    printf ("%lld\n", sum);

    return 0;
}
