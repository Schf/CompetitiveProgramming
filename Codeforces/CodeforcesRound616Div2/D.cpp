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
typedef pair <int, int> pii;
typedef vector <int> vi;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

bool palin (string a, string b)
{
	if (a.size () != b.size ()) return false;
	if (a.size () == 0) return true;
	vector <int> count_a (26, 0), count_b (26, 0);
	rep (i, 0, a.size ())
		++count_a[a[i] - 'a'], ++count_b[b[i] - 'a'];
	bool is = true;
	for (int i = 0; i < 26 && is; ++i)
		if (count_a[i] != count_b[i])
			is = false;
	return is;
}

bool indiv (string a, string b)
{
	if (!palin (a, b)) return false;
	bool is = true;
	for (int i = 1; i <= a.size () && is; ++i)
		if (palin (a.substr (0, i), b.substr (0, i)))
			false;
	return is;
}

bool check (string src)
{
	string cmp = src;
	next_permutation (cmp.begin (), cmp.end ());
	bool ans = false;
	while (!ans && cmp != src)
	{
		ans = indiv (src, cmp);
		next_permutation (cmp.begin (), cmp.end ());
	}
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		string src;
		int q, i, j;
		cin >> src >> q;
		for (i = 0; i < q; ++i)
		{
			int l, r;
			cin >> l >> r;
			if (check (src.substr (l, r - l))) cout << "Yes\n";
			cout << "No\n";
		}
	}

	return 0;
}


