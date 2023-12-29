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
	ll i, j, n, k;
	cin >> n >> k;
	vector <string> inp (n);
	vector <vector <ll>> alg (n, vector <ll> (n, 0));
	trav (s, inp) cin >> s;
	queue <pair <ll, ll>> bfs;
	bfs.push ({0, 0});
	alg[0][0] = k;
	while (!bfs.empty ())
	{
		auto cur = bfs.front ();
		bfs.pop ();
		ll cur_k = alg[cur.f][cur.s];
		if (inp[cur.f][cur.s] != 'a') --cur_k;
		if (cur.s + 1 < n && alg[cur.f][cur.s + 1] < cur_k)
			alg[cur.f][cur.s + 1] = cur_k,
			bfs.push ({cur.f, cur.s + 1});
		if (cur.f + 1 < n && alg[cur.f + 1][cur.s] < cur_k)
			alg[cur.f + 1][cur.s] = cur_k,
			bfs.push ({cur.f + 1, cur.s});
	}
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (alg[i][j])
				inp[i][j] = 'a';
	trav (v, alg)
	{
		trav (a, v) cout << a << ' ';
		cout << '\n';
	}
	trav (s, inp) cout << s << '\n';
	vector <vector <string>> alg2;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			for (ll cc = 0; cc < i + j; ++cc)
				alg2[i][j] += 'z';
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
		{
			if (j > 0)
				alg2[i][j] = min (alg2[i][j], alg2[i][j - 1]);
			if (i > 0)
				alg2[i][j] = min (alg2[i][j], alg2[i - 1][j]);
			alg2[i][j] += inp[i][j];
		}
	cout << alg2[n - 1][n - 1] << '\n';

	return 0;
}

