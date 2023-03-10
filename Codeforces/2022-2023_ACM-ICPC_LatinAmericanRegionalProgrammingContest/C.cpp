#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

#define SIGN(X) ((X)>0) - ((X)<0)

void floodfill (vector<vll> & map, int x, int y, int t)
{
	queue<pair<ll, ll>> q;
	q.push ({x, y});
	while (!q.empty())
	{
		auto p = q.front ();
		q.pop ();
		map[p.f][p.s] = t;
		if (auto x = p.f-1, y = p.s; map[x][y] == 0) map[x][y] = t, q.push({x, y});
		if (auto x = p.f+1, y = p.s; map[x][y] == 0) map[x][y] = t, q.push({x, y});
		if (auto x = p.f, y = p.s-1; map[x][y] == 0) map[x][y] = t, q.push({x, y});
		if (auto x = p.f, y = p.s+1; map[x][y] == 0) map[x][y] = t, q.push({x, y});
	}
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, MAP_S = 2001;
	cin >> n;

	vector <vll> map (MAP_S, vll (MAP_S, 0));

	for (i = 0; i < MAP_S; ++i)
		map[i][0] = map[i][MAP_S-1] = map[0][i] = map[MAP_S-1][i] = -1;

	ll x, y;
	cin >> x >> y;
	x *= 2; y *= 2;
	map[x][y] = -1;
	for (i = 0; i < n; ++i)
	{
		ll nx, ny;
		cin >> nx >> ny;
		nx *= 2; ny *= 2;
		ll dx = nx - x, dy = ny - y;

		for (; abs (dx) > 0; dx -= SIGN(dx))
			map[x + dx][y] = -1;

		for (; abs (dy) > 0; dy -= SIGN(dy))
			map[x][y + dy] = -1;

		map[nx][ny] = -1;
		x = nx, y = ny;
	}

	floodfill (map, 1, 1, -2);

	n = 1;
	for (i = 0; i < MAP_S; ++i)
		for (j = 0; j < MAP_S; ++j)
			if (map[i][j] == 0)
				floodfill (map, i, j, n++);

	vll count (n, 0);
	for (i = 1; i < MAP_S; i += 2)
		for (j = 1; j < MAP_S; j += 2)
			if (map[i][j] > 0)
				count[map[i][j]]++;
	
	cout << *max_element(count.begin (), count.end ()) << endl;

	return 0;
}
