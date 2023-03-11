#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

ll MOD = 1e+9 + 7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i, j, n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vll v(n);
		trav(e, v) cin >> e;
		if (n == 1)
		{
			cout << v[0] << endl;
			continue;
		}
		trav(e, v) if (e == 1)
			e++;
		set<pll> nums;
		for (i = 0; i < n; ++i)
			nums.insert({v[i], i});
		for (i = 0; i < 2*n; ++i)
		{
			auto p = *nums.begin();
			nums.erase(nums.begin());
			if (p.s < n && (v[p.s + 1] % v[p.s] == 0))
				v[p.s]++;
			p.f++;
			nums.insert (p);
		}
		trav(e, v) cout << e << ' ';
		cout << endl;
	}

	return 0;
}
