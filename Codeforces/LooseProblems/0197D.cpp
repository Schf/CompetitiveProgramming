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

int log2 (int a)
{
	int ans = 0;
	while (a >>= 1) ++ans;
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, n, m;
		cin >> n >> m;
		n = 1 << n;
		vector <int> tree (2*n);
		for (i = n; i < tree.size (); ++i)
			cin >> tree[i];
		for (i = n - 1; i > 0; --i)
		{
			if ((log2 (n) - log2 (i))%2)
				tree[i] = tree[i << 1] | tree[i << 1 | 1];
			else tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
		}
		for (int qq = 0; qq < m; ++qq)
		{
			cin >> i;
			i += n - 1;
			cin >> tree[i];
			for (i >>= 1; i > 0; i >>= 1)
				if ((log2 (n) - log2 (i))%2)
					tree[i] = tree[i << 1] | tree[i << 1 | 1];
				else tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
			cout << tree[1] << '\n';
		}
	}

	return 0;
}


