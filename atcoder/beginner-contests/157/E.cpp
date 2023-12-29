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
const ll MAXN = 1e+6+7;

vector <vector <int>> tree;
int n;

void update (int p, char c)
{
	//trav (v, tree)
	//{
	//	trav (a, v)
	//		cout << a << ' ';
	//	cout << '\n';
	//}
	//cout << "-----------------------------------------\n";
	int i, j; p += n;
	for (j = 0; j < 26; ++j)
		tree[p][j] = 0;
	tree[p][c - 'a'] = 1;
	for (i = p; i > 1; i >>= 1)
		for (j = 0; j < 26; ++j)
			tree[i >> 1][j] = tree[i][j] || tree[i ^ 1][j];
}

int query (int l, int r)
{
	int i, j;
	vector <int> res (26, 0);
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l&1)
		{
			for (j = 0; j < 26; ++j)
				res[j] = res[j] || tree[l][j];
			++l;
		}
		if (r&1)
		{
			--r;
			for (j = 0; j < 26; ++j)
				res[j] = res[j] || tree[r][j];
		}
	}
	int sum = 0;
	trav (a, res) if (a) ++sum;
	return sum;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		int i, j, q;
		string s;
		cin >> n >> s >> q;
		
		tree.resize (2*n, vector <int> (26, 0));
		for (i = 0; i < n; ++i)
			tree[i + n][s[i] - 'a'] = 1;
		for (i = n - 1; i > 0; --i)
			for (j = 0; j < 26; ++j)
				tree[i][j] = tree[i << 1][j] || tree[i << 1 | 1][j];
		
		for (int qqq = 0; qqq < q; ++qqq)
		{
			int type; cin >> type;
			if (type == 1)
			{
				int pos; char c; cin >> pos >> c; --pos;
				while (c < 'a' || 'z' < c) cin >> c;
				//cout << pos << ' ' << c << '\n';
				update (pos, c);
			}
			else
			{
				int l, r; cin >> l >> r; --l;
				cout << query (l, r) << '\n';
			}
		}
		//trav (v, tree)
		//{
		//	trav (c, v)
		//		cout << c << ' ';
		//	cout << '\n';
		//}
		//cout << "=================================================\n";
	}

	return 0;
}


