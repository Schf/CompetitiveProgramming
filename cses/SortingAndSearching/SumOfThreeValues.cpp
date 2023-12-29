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
		ll i, j, k, n, x;
		cin >> n >> x;
		vector <pair <ll, ll>> inp (n);
		for (i = 0; i < n; ++i)
			cin >> inp[i].f, inp[i].s = i + 1;
		sort (inp.begin (), inp.end ());
		for (k = 0; k < n; ++k)
			for (i = 0, j = n - 1; i < j; )
				if (i == k) ++i;
				else if (j == k) --j;
				else if (inp[i].f + inp[j].f + inp[k].f == x) goto end;
				else if (inp[i].f + inp[j].f + inp[k].f < x) ++i;
				else --j;
		end:;
		if (k >= n || j <= i || inp[i].f + inp[j].f + inp[k].f != x)
			cout << "IMPOSSIBLE\n";
		else
		{
			vector <ll> ans = {inp[i].s, inp[j].s, inp[k].s};
			sort (ans.begin (), ans.end ());
			trav (a, ans) cout << a << ' ';
			cout << '\n';
		}
	}

	return 0;
}


