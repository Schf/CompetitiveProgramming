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
vector <int> nums, tree;

int query (int l, int r)
{
	int ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1) ans += tree[l++];
		if (r&1) ans += tree[--r];
	}
	return ans;
}

void update (int p, int v)
{
	tree[p + n] = v;
	for (int i = p + n; i > 1; i >>= 1)
		tree[i >> 1] = tree[i] + tree[i^1];
}



int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j;
	cin >> n;
	nums.resize (n, 0);
	tree.resize (2*n);
	trav (a, nums) cin >> a;
	for (i = 2*n; i > 1; --i)
		if (i >= n) tree[i] = nums[i - n];
		else tree[i] = tree[i << 1] + tree[(i << 1) | 1];
	trav (a, tree) cout << a << ' ';
	cout << endl;
	int ord, pos1, pos2;
	while (cin >> ord >> pos1 >> pos2)
	{
		cout << ord << ' ' << pos1 << ' ' << pos2 << " |";
		if (ord == 1)
		{
			update (pos1, pos2);
			trav (a, tree) cout << ' ' << a;
			cout << '\n';
		}
		else
		{
			trav (a, tree) cout << ' ' << a;
			cout << " | " << query (pos1, pos2 + 1) << '\n';
		}
	}
	
	return 0;
}


