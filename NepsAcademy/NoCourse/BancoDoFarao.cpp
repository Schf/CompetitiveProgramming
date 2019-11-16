#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

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

#define DEBUG 1
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

int main ()
{
    int i, j;
    int T, N, Q, A, B;
    scanf ("%d", &T);
    while (T--)
    {
        scanf ("%d", &N);
        vi contas (N), seg (N*2 - 1);
        for (i = 0; i < N; i++)
        {
            scanf ("%d", &(contas[i]));
            seg[N - 1 + i] = contas[i];
        }
        for (i = seg.size () - 1; i != 0; i--)
        {
            ddprintf ("%d | ", i);
            trav (a, seg)
                ddprintf ("%d ", a);
            ddprintf ("\n");
            seg[(i - 1)/2] += seg[i];
        }
        ddprintf ("%d | ", i);
        trav (a, seg)
            ddprintf ("%d ", a);
        ddprintf ("\n");
        
        scanf ("%d", &Q);
        for (i = 0; i < Q; i++)
            scanf ("%d %d", &A, &B);

    }
    
    return 0;
}