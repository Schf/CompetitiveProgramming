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
    int i, j, n;
    string s;
    cin >> n;
    vector <string> S (n);
    vi T (n);
    for (i = 0; i < n; ++i)
        cin >> S[i] >> T[i];
    cin >> s;
    dd trav (a, S)
        cout << a << ' ';
    dd cout << '\n';
    dd trav (a, T)
        cout << a << ' ';
    dd cout << '\n' << s << '\n';
    for (i = j = n = 0; i < sz (S); ++i)
    {
        if (!j && S[i] == s) j = 1;
        else if (j) n += T[i];
    }
    cout << n << '\n';

    return 0;
}


