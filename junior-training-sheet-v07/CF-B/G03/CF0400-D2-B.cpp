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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	vector <pair <ll, ll>> pos (n);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			if (inp[i][j] == 'G') pos[i].f = j;
			else if (inp[i][j] == 'S') pos[i].s = j;
	set <ll> ans;
	for (i = 0; i < n; ++i)
		ans.insert (pos[i].s - pos[i].f);
	if (*ans.begin () < 0) cout << "-1\n";
	else cout << ans.size () << '\n';

	return 0;
}

