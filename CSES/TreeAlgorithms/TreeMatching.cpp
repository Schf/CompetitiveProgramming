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

vector <vector <ll>> tree;
vector <pair <ll, ll>> dp;
// dp[i].f = max if has, dp[i].s = max if hasn't

void dfs (ll tgt)
{
	dp[tgt].f = dp[tgt].s = 0;
	ll min_diff = INF;
	trav (v, tree[tgt])
		if (dp[v].f < 0)
			dfs (v),
			dp[tgt].f += dp[v].s,
			dp[tgt].s += dp[v].s,
			min_diff = min (min_diff, dp[v].s - dp[v].f);
	if (min_diff < INF)
		dp[tgt].s += 1 - min_diff;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		tree.resize (n);
		dp.resize (n, {-1, -1});
		for (i = 0; i < n - 1; ++i)
		{
			int a, b; cin >> a >> b; --a, --b;
			tree[a].push_back (b);
			tree[b].push_back (a);
		}
		dfs (0);
		cout << dp[0].s << '\n';
	}

	return 0;
}


