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

inline int F (int a, int b)
{
	return a & (~b);
}

int vec_val (vector <int> & vec)
{
	if (vec.size () == 1) return vec[0];
	int ans = F (vec[0], vec[1]);
	for (int i = 2; i < vec.size (); ++i)
		ans = F (ans, vec[i]);
	return ans;
}

vector <set <int>> alg;

int num_val (int a)
{
	int ans = 0;
	for (int j = 0; j < 32; ++j)
	{
		if (a >> j & 1)
		{
			if (alg[j].size () == 1)
				ans += 1 << j;
		}
	}
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1;
	//cin >> tc;
	while (tc--)
	{
		int i, j, n;
		cin >> n;
		vector <int> A (n), B (n), C (n);
		trav (a, A) cin >> a;
		alg.clear ();
		alg.resize (32, set <int> ());
		int maxi = 0;
		for (i = 0; i < A.size (); ++i)
		{
			for (j = 0; j < 32; ++j)
				if (A[i] >> j & 1)
					alg[j].insert (A[i]);
		}
		vector <int> vals (n);
		for (i = 0; i < A.size (); ++i)
			vals[i] = num_val (A[i]);
		for (i = 1; i < A.size (); ++i)
			if (vals[maxi] < vals[i])
				maxi = i;
		cout << A[maxi] << ' ';
		for (i = 0; i < A.size (); ++i)
			if (i != maxi)
				cout << A[i] << ' ';
		cout << '\n';
	}

	return 0;
}


