#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& (a) : (x))
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0); cin.exceptions (cin.failbit);

typedef long long ll;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mkp(x) make_pair ((x))

typedef vector<int> vi;
#define pb(x) push_back ((x))

#define DEBUG 0
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

#define ddprintfv(v) if (DEBUG) { trav (a, v) cout << a << " "; cout << "\n"; }

#define EXIT ddprintf ("Time elapsed %lf\n", 1.0 * clock() / CLOCKS_PER_SEC); exit (0)

const ll   MOD   =  1e+9+7;
const ll   INF   =  0x3f3f3f3f3f3f3f3f;
const int  INFi  =  0x3f3f3f3f;
const ll   MAXN  =  1e+6+7;

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    else {
        T g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}
 
template <typename T>
T modInv(T a, T m) {
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}
 
template <typename T>
T modDiv(T a, T b, T m) {
    return ((a % m) * modInv(b, m)) % m;
}
 
template<typename T>
T modMul(T a, T b, T m) {
    T x = 0, y = a % m;
    while (b > 0) {
        if (b % 2 == 1) x = (x + y) % m;
        y = (y * 2) % m; b /= 2;
    }
    return x % m;
}

int main ()
{
    int i, j;
    int X, Y;
    scanf ("%d %d", &X, &Y);
    
    if ((X + Y)%3 != 0 || min (X, Y) * 2 < max (X, Y))
    {
        printf ("0\n");
        EXIT;
    }

    ll n = (X+Y)/3;
    ll k = n/2 - abs (X-Y)/2;
    ddprintf ("%lld %lld\n", n, k);
    ll num = 1, den = 1;
    for (i = n; i > max (k, n - k); i--)
        num = (num * i) % MOD;
    for (i = min (k, n - k); i > 0; i--)
        den = (den * i) % MOD;
    ddprintf ("%lld %lld\n", num, den);

    printf ("%lld\n", modDiv (num, den, MOD));

    EXIT;
}