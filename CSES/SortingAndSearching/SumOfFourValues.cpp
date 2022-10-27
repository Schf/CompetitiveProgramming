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

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, k, n, x, a = 0, b = 0, c = 0, d = 0;
		cin >> n >> x;
		vector <pair <ll, ll>> inp (n);
		for (i = 0; i < n; ++i)
			cin >> inp[i].f, inp[i].s = i + 1;
		sort (inp.begin (), inp.end ());
		//trav (p, inp) cout << p.f << ' ' << p.s << "| ";
		//cout << '\n';
		for (a = 0; a <= n - 4; ++a)
			for (d = a + 3; d < n; ++d)
				for (b = a + 1, c = d - 1; b < c; )
					if (inp[a].f + inp[b].f + inp[c].f + inp[d].f == x) goto end;
					else if (inp[a].f + inp[b].f + inp[c].f + inp[d].f < x) ++b;
					else --c;
		end:;
		if (a >= n || b >= n || c >= n || d >= n || a < 0 || b < 0 || c < 0 || d < 0 ||
				a >= d || b >= c || inp[a].f + inp[b].f + inp[c].f + inp[d].f != x)
			cout << "IMPOSSIBLE\n";
		else
		{
			vector <ll> ans = {inp[a].s, inp[b].s, inp[c].s, inp[d].s};
			sort (ans.begin (), ans.end ());
			trav (a, ans) cout << a << ' ';
			cout << '\n';
		}
	}

	return 0;
}
 
