#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, r, g, b;
	cin >> r >> g >> b;
	vector <vector <ll>> S (3);
	S[0].resize (r);
	S[1].resize (g);
	S[2].resize (b);
	trav (a, S[0]) cin >> a;
	trav (a, S[1]) cin >> a;
	trav (a, S[2]) cin >> a;
	sort (S[0].begin (), S[0].end ());
	sort (S[1].begin (), S[1].end ());
	sort (S[2].begin (), S[2].end ());
	vector <ll> idx = {0, 1, 2};
	ll ans = 0;
	while ((S[0].size ()>0) + (S[1].size ()>0) + (S[2].size ()>0) > 1)
	{
		sort (idx.begin (), idx.end (), [&] (auto & a, auto & b)
		{
			if (S[a].empty ()) return true;
			if (S[b].empty ()) return false;
			return S[a].back () < S[b].back ();
		});
		ans += S[idx[2]].back () * S[idx[1]].back ();
		S[idx[2]].pop_back ();
		S[idx[1]].pop_back ();
	}
	cout << ans << '\n';

	return 0;
}

