#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int n;
vector <int> nums;
vector <pair <int, int>> max_tree, min_tree; // .f = val, .s = pos

void build ()
{
	for (int i = 0; i < n; ++i)
		max_tree[n + i] = {nums[i], i},
		min_tree[n + i] = {nums[i], i};
	for (int i = n - 1; i > 0; --i)
		max_tree[i] = max (max_tree[i << 1], max_tree[(i << 1) | 1]),
		min_tree[i] = min (min_tree[i << 1], min_tree[(i << 1) | 1]);
}

void update (int p, int value)
{
	p = p + n;
	max_tree[p] = max (max_tree[p], {value, p - n});
	min_tree[p] = min (min_tree[p], {value, p - n});
	for (int i = p; i > 1; i >>= 1)
		max_tree[i >> 1] = max (max_tree[i], max_tree[i^1]),
		min_tree[i >> 1] = min (min_tree[i], min_tree[i^1]);
}

pair <int, int> max_query (int l, int r)
{
	pair <int, int> ans (-1, -1);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1) ans = max (ans, max_tree[l++]);
		if (r&1) ans = max (ans, max_tree[--r]);
	}
	return ans;
}

pair <int, int> min_query (int l, int r)
{
	pair <int, int> ans (INF, INF);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1) ans = min (ans, min_tree[l++]);
		if (r&1) ans = min (ans, min_tree[--r]);
	}
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j, m;
	cin >> n >> m;
	nums.resize (n);
	max_tree.resize (2*n, {-1, -1});
	min_tree.resize (2*n, {INF, INF});
	trav (a, nums) cin >> a;
	build ();
	while (m--)
	{
		int ord, pos1, pos2;
		cin >> ord >> pos1 >> pos2;
		if (ord == 1) update (pos2 - 1, pos1);
		if (ord == 2)
		{
			pair <int, int> cur_max = max_query (pos1 - 1, pos2);
			pair <int, int> cur_min = min_query (pos1 - 1, cur_max.s);
			cur_min = min (cur_min, min_query (cur_max.s + 1, pos2));
			int maxdiff = cur_max.f - cur_min.f;
			cur_min = min_query (pos1 - 1, pos2);
			cur_max = max_query (pos1 - 1, cur_min.s);
			cur_max = max (cur_max, max_query (cur_min.s + 1, pos2));
			maxdiff = max (maxdiff, cur_max.f - cur_min.f);
			cout << maxdiff << '\n';
		}
	}

	return 0;
}


