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

inline ll log (ll a, ll b = 2)
{
	ll i = -1;
	for (; a > 0; ++i, a /= b)
	return i;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j, n, q;
	cin >> n >> q;
	vector <set <int>> tree (2*n);
	for (i = 0; i < n; ++i)
		cin >> j, tree[i + n].insert (j);
	for (i = n - 1; i > 0; --i)
	{
		trav (a, tree[i << 1])
			tree[i].insert (a);
		trav (a, tree[i << 1 | 1])
			tree[i].insert (a);
	}
	/*
	for (i = 0; i < q; ++i)
	{
		int l, r;
		cin >> l >> r;
		set<int> ans;
		for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1)
		{
			if (l&1)
			{
				trav (a, tree[l])
					ans.insert (a);
				++l;
			}
			if (r&1)
			{
				--r;
				trav (a, tree[r])
					ans.insert (a);
			}
		}
		cout << ans.size () << endl;
	}
	*/

	return 0;
}

