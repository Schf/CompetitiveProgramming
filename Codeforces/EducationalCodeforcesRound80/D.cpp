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

int a1, a2;
mi A;

bool can (int check)
{
    vi msk(1 << (sz (A[0])), -1);
    for (int i = 0; i < sz (A); ++i)
    {
        int i_msk = 0;
        for (int j = 0; j < sz (A[i]); ++j)
        {
            if (A[i][j] >= check)
                i_msk |= 1 << j;
        }
        msk[i_msk] = i;
    }
    if (msk[(1 << (sz (A[0]))) - 1] != -1)
    {
        a1 = a2 = msk[(1 << (sz (A[0]))) - 1];
        return true;
    }
    for (int msk1 = 0; msk1 < (1 << (sz (A[0]))); ++msk1)
    {
        for (int msk2 = 0; msk2 < (1 << (sz (A[0]))); ++msk2)
        {
            if (((msk1 | msk2) == ((1 << (sz (A[0]))) - 1)) && (msk[msk1] != -1 && msk[msk2] != -1))
            {
                a1 = msk[msk1];
                a2 = msk[msk2];
                return true;
            }
        }
    }
    return false;
}

int main ()
{
    FASTIO;
    int i, j, n, m;
    cin >> n >> m;
    A.resize (n, vi (m));
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> A[i][j];
    dd trav (v, A)
    {
        trav (a, v)
            printf ("% 3d", a);
        printf ("\n");
    }
    ll ub = MOD, lb = 0, mb;
    while (ub - lb > 1)
    {
        mb = (ub + lb)/2;
        if (can (mb)) lb = mb;
        else ub = mb;
    }
    cout << a1 + 1 << ' ' << a2 + 1 << '\n';

    return 0;
}


