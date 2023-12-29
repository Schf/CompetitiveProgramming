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
    int i, j, n, t;
    int mn, mx, mnl, mxr;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vll A (n + 1);
        mn = mx = mnl = mxr = 0;
        for (i = 1; i <= n; ++i)
        {
            cin >> A[i];
            A[i] += A[i - 1];
            if (A[i] <= A[mn])
                mn = i;
            if (A[mx] < A[i])
                mx = i;
            if (i <= mx && A[i] <= A[mnl])
                mnl = i;
        }
        for (i = mxr = n; i >= mn; --i)
            if (A[mxr] <= A[i])
                mxr = i;
        if (mn == 0 && mx == n)
        {
            for (mnl = i = 1; i <= n; ++i)
                if (A[i] <= A[mnl])
                    mnl = i;
            for (mxr = i = n - 1; i >= 0; --i)
                if (A[mxr] <= A[i])
                    mxr = i;
            if (A[mxr] - A[mn] < A[mx] - A[mnl]) mn = mnl;
            else mx = mxr;
        }
        dd trav (a, A)
            printf ("% 3lld", a);
        dd printf ("\nmn:% 3lld, mxr:% 3lld, mx:% 3lld, mnl:% 3lld\n",
                A[mn], A[mxr], A[mx], A[mnl]);
        if (A[mx] - A[mn] < A.back () - A[0]) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}

