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

vector <ll> perm, cor, viz;

inline bool eq (ll j, ll i)
{
	return (perm[j] == i) || (cor[perm[j]] == cor[i]);
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		perm.resize (n);
		cor.resize (n);
		viz.resize (n, 0);
		trav (a, perm) cin >> a, --a;
		trav (a, cor) cin >> a, --a;
		ll ans = INF, cur = 0;
		for (i = 0; i < n; ++i)
		{
			if (viz[i]) continue;
			viz[i] = 1;
			if (perm[i] == i) { ans = 1; break; }
			for (j = perm[i], cur = 2;
					!eq (j, j) && !eq (j, i);
					viz[j] = 1, j = perm[j], ++cur);
			if (perm[j] == j) { ans = 1; break; }
			ans = min (ans, cur);
		}
		cout << ans << '\n';
	}

	return 0;
}


