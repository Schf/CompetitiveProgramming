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

int main ()
{
    FASTIO;
    int N, M, i, j;
    deque <char> ts;
    for (i = 0; i < 16; i++)
        ts.pb (i + 'A');
    for (i = 0; i < 15; i++)
    {
        trav (a, ts)
            ddprintf ("%c | ", a);
        scanf ("%d %d", &M, &N);
        ddprintf ("%d %d | %d\n", M, N, i);
        if (M > N)
        {
            ts.pb (ts.front ());
            ts.pop_front ();
            ts.pop_front ();
        }
        else
        {
            ts.pop_front ();
            ts.pb (ts.front ());
            ts.pop_front ();
        }
    }
    printf ("%c\n", ts.front ());
    
    return 0;
}