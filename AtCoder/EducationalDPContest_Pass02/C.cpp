#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

#define trav(a, A) for (auto & a : A)

const int INF = 1e9;

int main ()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    int i, j, n;
    cin >> n;
    vector <vi> dp (n, vi (3)), hap (n, vi (3));
    // dp[i][j] felicidade maxima dia i, escolhendo j
    trav (v, hap)
        trav (a, v)
            cin >> a;
    for (i = 0; i < 3; ++i)
        dp[0][i] = hap[0][i];
    for (i = 1; i < n; ++i)
    {
        dp[i][0] = max (dp[i-1][1], dp[i-1][2]) + hap[i][0];
        dp[i][1] = max (dp[i-1][0], dp[i-1][2]) + hap[i][1];
        dp[i][2] = max (dp[i-1][0], dp[i-1][1]) + hap[i][2];
    }
    cout << max (dp[n-1][0], max (dp[n-1][1], dp[n-1][2])) << '\n';

    return 0;
}
