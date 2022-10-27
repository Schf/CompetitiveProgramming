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

inline bool valid (ll y, ll x, ll h, ll w)
{
	return 0 <= y && y < h && 0 <= x && x < w;
}

vector <pair <ll, ll>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, w, h;
	cin >> n;
	vector <string> nomes (n);
	trav (s, nomes) cin >> s;
	cin >> w >> h;
	vector <vector <ll>> map (h, vector <ll> (w));
	vector <pair <string, pair <ll, ll>>> out (n);
	for (i = 0; i < n; ++i)
		out[i].f = nomes[i];
	trav (v, map) trav (a, v) cin >> a;
	for (ll pos = 0; pos < h*w; ++pos)
	{
		if (map[pos/w][pos%w] <= 0) continue;
		queue <pair <ll, ll>> dfs;
		dfs.push ({pos/w, pos%w});
		map[pos/w][pos%w] = -map[pos/w][pos%w];
		ll cur = 1;
		while (!dfs.empty ())
		{
			auto pp = dfs.front ();
			dfs.pop ();
			trav (d, dirs)
				if (valid (pp.f + d.f, pp.s + d.s, w, h))
					if (map[pp.f + d.f][pp.s + d.s] > 0)
						++cur, dfs.push ({pp.f + d.f, pp.s + d.s}),
						map[pp.f + d.f][pp.s + d.s] = -map[pp.f + d.f][pp.s + d.s];
		}
		out[-map[pos/w][pos%w] - 1].s.f++;
		out[-map[pos/w][pos%w] - 1].s.s = max (out[-map[pos/w][pos%w] - 1].s.s, cur);
	}
	sort (out.begin (), out.end ());
	trav (s, out) cout << s.f << ' ' << s.s.f << ' ' << s.s.s << '\n';

	return 0;
}

