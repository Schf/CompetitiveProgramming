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
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+3 + 1;

int main ()
{
    FASTIO;
    int i, j, n, T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector <pii> boxes (n);
        trav (p, boxes)
            cin >> p.f >> p.s;
        boxes.insert (boxes.begin (), {0,0});
        sort (all (boxes));
        for (i = 1; i < boxes.size (); ++i)
            if (boxes[i - 1].f > boxes[i].f || boxes[i - 1].s > boxes[i].s)
                break;
        if (i < boxes.size ()) cout << "NO\n";
        else
        {
            cout << "YES\n";
            for (i = 1; i < boxes.size (); ++i)
            {
                for (j = 0; j < boxes[i].f - boxes[i - 1].f; ++j)
                    cout << 'R';
                for (j = 0; j < boxes[i].s - boxes[i - 1].s; ++j)
                    cout << 'U';
            }
            cout << '\n';
        }
    }

    return 0;
}


