#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

#define trav(a, A) for (auto & a : A)

const int INF = 1e9;
const ll INFLL = 1e18;

int da[] = {0, 1, 2}, db[] = {1, 0, 2}, dc[] = {2, 0, 1};

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    int i, j, n, w;
    cin >> n >> w;
    vll W (n), V (n);
    for (i = 0; i < n; ++i)
        cin >> W[i] >> V[i];
    vll dp (1e5+7, INFLL);
    dp[0] = 0;
    for (i = 0; i < n; ++i)
        for (j = 1e5+6 - V[i]; j >= 0; --j)
            dp[j + V[i]] = min (dp[j + V[i]], dp[j] + W[i]);
    ll value = 0;
    for (i = 0; i < 1e5+7; ++i)
        if (dp[i] <= w)
            value = max (value, (ll)i);
    cout << value << '\n';

    return 0;
}
