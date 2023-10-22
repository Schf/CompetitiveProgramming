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

int main ()
{
    FASTIO;
    int i, j, n, k;
    cin >> n;
    if (n == 2)
    {
        cout << "-1\n";
    }
    else
    {
        vi C (n), A;
        vector <unordered_set <int> > N (n);
        set <int> G;
        for (i = 0; i < n; ++i)
            G.insert (i);
        for (i = 0; i < n; ++i)
        {
            cin >> C[i]; --C[i];
            N[C[i]].insert(i);
        }
        for (i = 0; i < n; ++i)
            if (sz (N[i]) == n - 1)
            {
                A.pb (i);
                G.erase (i);
                break;
            }
        dd trav (s, N)
        {
            for (i = 0; i < n; ++i)
                if (s.find (i) == s.end ())
                    cout << "0 ";
                else
                    cout << "1 ";
            cout << endl;
        }
        dd if (sz (A)) cout << A[0] << endl;
        dd cout << "--------------------------------" << endl;
        if (!sz (A))
        {
            A.pb (0);
            G.erase (0);
        }
        for (i = sz (A); i < n; ++i)
        {
            dd cout << "A: ";
            dd trav (a, A)
                cout << a << " ";
            dd cout << endl << "G: ";
            dd trav (a, G)
                cout << a << " ";
            dd cout << endl << "--------------------------------" << endl;
            auto itt = G.begin ();
            if (C[A[i - 1]] == *itt) ++itt;
            if (itt == G.end ())
            {
                --itt;
                int ax = *itt;
                for (k = 1; k <= i && C[A[i - k]] == ax; ++k);
                --k;
                for (j = 0; j < k; ++j)
                {
                    G.insert (A.back ());
                    A.pop_back ();
                }
                A.pb (ax);
                G.erase (ax);
                i = sz (A) - 1;
            }
            else
            {
                A.pb (*itt);
                G.erase (itt);
            }
        }
        cout << A[0] + 1;
        for (i = 1; i < n; ++i)
            cout << ' ' << A[i] + 1;
        cout << endl;
    }

    return 0;
}


