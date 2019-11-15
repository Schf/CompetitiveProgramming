#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& (a) : (x))
#define all(x) (x).begin (), (x).end ()
#define sz(x) (int) (x).size ()
#define FASTIO cin.sync_with_stdio (0); cin.tie (0);// cin.exceptions (cin.failbit);

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
    //FASTIO;
    int T, i, j;
    scanf ("%d\n",  &T);
    vi A; string line;
    for (i = 0; i < T; i++)
    {
        getline (cin, line);
        trav (c, line)
        {
            if (c == '}')
            {
                if (A.size () == 0 || A.back () != '{')
                {
                    printf ("N\n");
                    return 0;
                }
                else
                    A.pop_back ();
            }
            else if (c == '{')
                A.pb (c);
        }
    }
    if (A.size () == 0)
        printf ("S\n");
    else
        printf ("N\n");

    return 0;
}