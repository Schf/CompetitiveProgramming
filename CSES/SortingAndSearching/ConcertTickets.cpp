#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"
 
#include <bits/stdc++.h>
using namespace std;
 
#define trav(a, A) for (auto & a : A)
#define f first
#define s second
 
typedef long long ll;
 
const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;
 
int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin.exceptions (cin.failbit);
    ll tc = 1; //cin >> tc;
    while (tc--)
    {
        ll i, j, n, m;
        cin >> n >> m;
        multiset <ll> st;
        for (i = 0; i < n; ++i)
        {
            cin >> j;
            st.insert (j);
        }
        for (i = 0; i < m && st.size (); ++i)
        {
            cin >> j;
            if (j < *(st.begin ()))
            {
                cout << -1 << '\n';
                continue;
            }
            auto itt = st.upper_bound (j);
            cout << *(--itt) << '\n';
            st.erase (itt);
        }
        for (; i < m; ++i) cout << -1 << '\n';
    }
 
    return 0;
}
