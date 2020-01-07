#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"

#include <bits/stdc++.h>
#define DEBUG 1

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
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
#define mp(a, b) make_pair ((a), (b))
typedef vector <int> vi;
#define pb(a) push_back ((a))

const ll MOD = 1e+9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int INFi = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
    FASTIO;
    int i, j;
    string s, b;
    vi vw ('z' + 1, 1);
    vw['a'] = vw['e'] = vw['i'] = vw['o'] = vw['u'] = vw['y'] = 0;
    cin >> b;
    trav (a, b)
    {
        if (a < 'a') a += 'a' - 'A';
        if (vw[a]) {s += '.'; s += a;}
    }
    cout << s << "\n";

    return 0;
}
