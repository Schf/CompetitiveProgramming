#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

#define trav(a, A) for (auto & a : A)

const int INF = 1e9;
const ll INFLL = 1e18;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    int i, j, n, w;
    string s, t;
    cin >> s >> t;
    vector <vi> dp (s.size () + 1, vi (t.size () + 1, 0));
    for (i = 1; i <= s.size (); ++i)
    {
        for (j = 1; j <= t.size (); ++j)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max (dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        }
    }
    vector <char> pilha;
    for (i = s.size (), j = t.size (); i > 0 && j > 0;)
        if (dp[i-1][j] == dp[i][j]) --i;
        else if (dp[i][j - 1] == dp[i][j]) --j;
        else pilha.push_back (s[--i]), --j;
    while (pilha.size ())
    {
        cout << pilha.back ();
        pilha.pop_back ();
    }
    cout << '\n';

    return 0;
}
