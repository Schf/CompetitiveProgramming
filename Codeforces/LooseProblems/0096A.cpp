#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 0

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define rall(a) (a).rbegin (), (a).rend ()
#define sz(a) (int) (a).size ()
#define szl(a) (int) (a).length ()
#define FASTIO cin.sync_with_stdio(); cin.tie(0); cin.exceptions (cin.failbit);

typedef long long ll;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp(a, b) make_pair ((a), (b))
typedef vector <int> vi;
#define pb(a) push_back ((a))

#define ddtrav(a, A) if (DEBUG) trav (a, A)
#define ddcout if (DEBUG) cout
#define ddprintf(fmt, ...) if (DEBUG) printf (fmt, ##__VA_ARGS__)

int main ()
{
    FASTIO;
    int i, j, f;
    string s;
    cin >> s;
    for (i = j = 1, f = 0; i < szl (s) && !f; i++)
    {
        if (s[i - 1] == s[i])
            j++;
        else j = 1;
        if (j >= 7)
            f = 1;
        ddprintf ("i:% 3d, j:% 3d, f:% 3d, s[% 3d]:% 3d\n", i, j, f, i, s[i]);
    }
    if (f) cout << "YES";
    else cout << "NO";
    cout << "\n";

    return 0;
}
