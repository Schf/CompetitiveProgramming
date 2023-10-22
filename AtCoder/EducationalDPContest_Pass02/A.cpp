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
    vi dp (n, INF), cost (n);
    trav (a, cost)
        cin >> a;
    dp[0] = 0;
    for (i = 1; i < n; ++i)
        for (j = 1; j <= 2 && i - j >= 0; ++j)
            dp[i] = min (dp[i], dp[i - j] + abs (cost[i - j] - cost[i]));
    cout << dp[n - 1] << '\n';

    return 0;
}
