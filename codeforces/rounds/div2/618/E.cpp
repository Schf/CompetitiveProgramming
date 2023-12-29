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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j, n;
	cin >> n;
	vector <int> A (n);
	set <pair <double, int>> st;
	trav (a, A) cin >> a;
	double cur_m = A[0];
	st.insert ({cur_m, 1});
	for (i = 1; i < A.size (); ++i)
	{
		cur_m = (cur_m*i + A[i])/(i + 1);
		st.insert ({cur_m, i + 1});
	}
	st.insert ({cur_m, i + 1});
	double corr_m = 0;
	int corr_n = 0;
	for (i = 0; i < A.size ();)
	{
		while (i >= st.begin ()->s) st.erase (st.begin ());
		auto cur_p = *(st.begin ());
		for (; i < cur_p.s; ++i)
			printf ("%.10lf\n", (cur_p.f*cur_p.s - corr_m*corr_n)/(cur_p.s - corr_n));
		corr_m = cur_p.f;
		corr_n = cur_p.s;
	}

	return 0;
}


