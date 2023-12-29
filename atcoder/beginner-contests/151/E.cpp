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
const ll MAXN = 1e+5+7;

ll fac[MAXN] = {1, 1}, facInv[MAXN] = {1, 1}, inv[MAXN] = {0, 1};

// for (i = 2; i < MAXN; ++i)
// {
//     fac[i] = fac[i - 1] * i % MOD;
//     inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
//     facInv[i] = facInv[i - 1] * inv[i] % MOD;
// }

ll calc (int n, int k)
{
    if (n < k || n < 0 || k < 0) return 0;
    return fac[n] * facInv[k] % MOD * facInv[n - k] % MOD;
}

ll mod_sum (ll a, ll b)
{
    a += b;
    if (a > MOD) a -= MOD;
    else if (a < 0) a += MOD;
    return a;
}

int main ()
{
    FASTIO;
    ll i, j, n, k, sum = 0, l;
    cin >> n >> k;
    vll A (n);
    trav (a, A)
        cin >> a;
    sort (all (A));
    for (i = 2; i < MAXN; ++i)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        facInv[i] = facInv[i - 1] * inv[i] % MOD;
    }
    for (i = sum = 0; i < n; ++i)
    {
        ll qnt_min = calc (n - i - 1, k - 1), qnt_max = calc (i, k - 1);
        sum = mod_sum (sum, ((mod_sum (qnt_max, -qnt_min))*A[i])%MOD);
    }
    cout << sum << '\n';

    return 0;
}


