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
	ll i, j, n, p;
	cin >> n >> p;
	vector <pair <ll, ll>> inp (n);
	vector <ll> ff (n), fs (n), sf (n), ss (n);
	trav (p, inp)
	{
		cin >> p.f >> p.s;
		--p.f, --p.s;
		if (p.f > p.s) swap (p.f, p.s);
		++ff[p.f], ++fs[p.s];
	}
	sort (inp.begin (), inp.end ());
	
	vector <vector <ll>> mp (n, vector <ll> (n, 0));
	vector <ll> freq (n, 0);
	trav (p, inp)
		++mp[p.f][p.s], ++mp[p.s][p.f],
		++freq[p.f], ++freq[p.s];
	ll ans = 0;
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			if (freq[i] + freq[j] - mp[i][j] >= p)
				++ans;
	cout << ans << '\n';

	/*trav (p, inp) cout << p.f << ' ' << p.s << " | ";
	cout << '\n';
	iota (sf.begin (), sf.end (), 0);
	iota (ss.begin (), ss.end (), 0);
	sort (sf.begin (), sf.end (), [&] (auto a, auto b)
	{
		if (ff[a] == ff[b]) return a < b;
		return ff[a] < ff[b];
	});
	sort (ss.begin (), ss.end (), [&] (auto a, auto b)
	{
		if (fs[a] == fs[b]) return a < b;
		return fs[a] < fs[b];
	});
	trav (a, sf) cout << ff[a] << ' ';
	cout << '\n';
	trav (a, ss) cout << fs[a] << ' ';
	cout << '\n';*/

	return 0;
}

