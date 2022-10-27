#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

#define trav(a, A) for (auto & a : A)

const int INF = 1e9;

int da[] = {0, 1, 2}, db[] = {1, 0, 2}, dc[] = {2, 0, 1};

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    int i, j, n, w;
    cin >> n >> w;
    vi W (n), V (n);
    for (i = 0; i < n; ++i)
        cin >> W[i] >> V[i];
    vll dp (w + 1);
    for (i = 0; i < n; ++i)
        for (j = w - W[i]; j >= 0; --j)
            dp[j + W[i]] = max (dp[j + W[i]], dp[j] + V[i]);
    cout << dp[w] << '\n';

    return 0;
}
