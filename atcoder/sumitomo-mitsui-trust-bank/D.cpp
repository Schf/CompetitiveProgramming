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
//#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

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

unordered_set <string> st;
string s;

int dp (int pos)
{
    auto it = st.find (s);
    if (it != st.end ())
        return 0;
    if (s.length () == 3)
    {
        st.insert (s);
        return 1;
    }
    if (pos < 0)
    {
        st.insert (s);
        return 0;
    }
    char c = s[pos];
    int r;
    s.erase (s.begin () + pos);
    r = dp (pos - 1);
    s.insert (s.begin () + pos, c);
    st.insert (s);
    return r;
}

int main ()
{
    //FASTIO;
    int i, j;
    scanf ("%d\n", &j);
    cin >> s;
    trav (a, s)
        a -= '0';
    printf ("%d\n", dp (s.length () - 1));

    return 0;
}
