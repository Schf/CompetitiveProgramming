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

struct comp {
    bool operator() (pair <ll, ll> a, pair <ll, ll> b) {
    	if (a.s - a.f == b.s - b.f) return a.f < b.f;
        return a.s - a.f > b.s - b.f;
    }
};

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, x;
		cin >> x >> n;
		multiset <pair <ll, ll>, comp> ans;
		set <pair <ll, ll>> arm;
		arm.insert ({0, x});
		ans.insert ({0, x});
		for (i = 0; i < n; ++i)
		{
			cin >> j;
			auto itt = arm.upper_bound ({j, INF});
			--itt;
			ans.erase (*itt);
			ans.insert ({itt->f, j});
			ans.insert ({j, itt->s});
			arm.insert ({itt->f, j});
			arm.insert ({j, itt->s});
			arm.erase (itt);
			cout << ans.begin ()->s - ans.begin ()->f << ' ';
		}
		cout << '\n';
	}

	return 0;
}


