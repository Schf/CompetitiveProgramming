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
	vector <pair <ll, ll>> brid;
	vector <pair <ll, ll>> inp (--n);
	ll last_beg, last_end, next_beg, next_end;
	cin >> last_beg >> last_end;
	for (i = 0; i < n; ++i)
	{
		cin >> next_beg >> next_end;
		inp[i] = {next_beg - last_end, next_end - last_beg};
		last_beg = next_beg;
		last_end = next_end;
	}
	vector <ll> inpi (n);
	iota (inpi.begin (), inpi.end (), 0);
	sort (inpi.begin (), inpi.end (), [&] (auto & a, auto & b)
	{
		if (inp[a].s - inp[a].f == inp[b].s - inp[b].f)
			return inp[a] < inp[b];
		return inp[a].s - inp[a].f < inp[b].s - inp[b].f;
	});
	for (i = 0; i < m; ++i)
	{
		cin >> j;
		brid.push_back ({j, i + 1});
	}
	sort (brid.begin (), brid.end ());
	vector <ll> ans (n);
	for (i = 0; i < n; ++i)
	{
		auto bridge = upper_bound (brid.begin (), brid.end (),
				make_pair (inp[inpi[i]].f, -1));
		if (bridge == brid.end () || bridge->f > inp[inpi[i]].s)
		{
			cout << "No\n";
			return 0;
		}
		ans[inpi[i]] = bridge->s;
		brid.erase (bridge);
	}
	cout << "Yes\n";
	trav (a, ans) cout << a << ' ';
	cout << '\n';

	return 0;
}

