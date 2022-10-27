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

inline bool are_pals (string & a, string & b)
{
	for (int i = 0; i < a.size (); ++i)
		if (a[i] != b[b.size () - 1 - i])
			return false;
	return true;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int i, j, n, m;
	cin >> n >> m;
	vector <string> giv (n);
	vector <pair <int, int>> pals;
	vector <bool> viz (n);
	trav (s, giv) cin >> s;
	int sum = 0;
	for (i = 0; i < n; ++i)
		if (!viz[i])
			for (j = i + 1; j < n; ++j)
				if (!viz[j])
					if (are_pals (giv[i], giv[j]))
						viz[i] = viz[j] = 1, pals.push_back ({i, j});
	for (i = 0; i < n; ++i)
		if (!viz[i])
			if (are_pals (giv[i], giv[i]))
			{
				viz[i];
				pals.push_back ({i, i});
				break;
			}
	string ans ("");
	if (pals.size () && pals.back ().f == pals.back ().s)
		ans = giv[pals.back ().f], pals.pop_back ();
	while (pals.size ())
		ans = giv[pals.back ().f] + ans + giv[pals.back ().s], pals.pop_back ();
	cout << ans.size () << '\n' << ans << '\n';

	return 0;
}


