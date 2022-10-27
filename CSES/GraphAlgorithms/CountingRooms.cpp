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

vector <pair <ll, ll>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector <vector <ll>> inp;

ll n, m;

bool valid (ll a, ll b)
{
	return 0 <= a && a < n &&
			0 <= b && b < m &&
			inp[a][b] == 0;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j;
	string s;
	cin >> n >> m;
	inp.resize (n, vector <ll> (m));
	trav (v, inp)
		for (cin >> s, i = 0; i < m; ++i)
			v[i] = ((s[i] == '.') ? (0) : (-1));
	for (i = 1, j = 0; true; ++i)
	{
		queue <pair <ll, ll>> bfs;
		for (; j < n*m; ++j)
			if (valid (j/m, j%m))
				break;
		if (j >= n*m)
			break;
		inp[j/m][j%m] = i;
		bfs.push ({j/m, j%m});
		while (!bfs.empty ())
		{
			ll a = bfs.front ().f;
			ll b = bfs.front ().s;
			bfs.pop ();
			trav (d, dirs)
				if (valid (a + d.f, b + d.s))
					inp[a + d.f][b + d.s] = i,
					bfs.push ({a + d.f, b + d.s});
		}
	}
	cout << --i << '\n';

	return 0;
}


