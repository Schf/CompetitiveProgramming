#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#define DEBUG 1
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

// 00:28:00h
vector <vector <vector <double> > > dp (301, vector <vector <double> > (301, 
        vector <double> (301, -1)));

double solve (int a0, int a1, int a2, int a3)
{
    if (a1 < 0 || a2 < 0 || a3 < 0)
        return 0;
    if (a1 == 0 && a2 == 0 && a3 == 0)
        return 0;
    if (dp[a1][a2][a3] > -0.5)
        return dp[a1][a2][a3];
    double sum = a1 + a2 + a3;
    double p = (a3/sum)*solve (a0, a1, a2+1, a3-1);
    p += (a2/sum)*solve (a0, a1+1, a2-1, a3);
    p += (a1/sum)*solve (a0+1, a1-1, a2, a3);
    dd printf ("a0:% 3d, a1:% 3d, a2:% 3d, a3:% 3d, pb:% 3.4lf, ", a0, a1, a2, a3, p);
    p += (sum + a0)/sum;
    dd printf ("pa:% 3.4lf\n", p);
    return dp[a1][a2][a3] = p;
}

int main ()
{
    FASTIO;
    int i, j, n;
    cin >> n;
    vi A (4);
    for (i = 0; i < n; i++)
    {
        cin >> j;
        A[j]++;
    }
    dd trav (a, A)
        cout << a << ' ';
    dd cout << endl;
    printf ("%.10lf\n", solve (A[0], A[1], A[2], A[3]));

    return 0;
}

