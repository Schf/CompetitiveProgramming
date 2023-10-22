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
	ll i, j, n, c;
    string s, t, ans, cur;
    cin >> s >> t;
    ll dp[s.size () + 1][t.size () + 1][201];
    for (i = 0; i < s.size () + 1; ++i)
        for (j = 0; j < t.size () + 1; ++j)
            for (ll k = 0; k < 201; ++k)
                dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    
    

	return 0;
}

