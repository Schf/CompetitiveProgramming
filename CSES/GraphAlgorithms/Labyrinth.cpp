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
			inp[a][b] >= 0;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j;
	string s;
	cin >> n >> m;
	inp.resize (n, vector <ll> (m));
	queue <pair <ll, ll>> bfs;
	pair <ll, ll> end, bgn;
	for (i = 0; i < n; ++i)
		for (cin >> s, j = 0; j < m; ++j)
			if (s[j] == '#') inp[i][j] = -1;
			else if (s[j] == '.') inp[i][j] = INF;
			else if (s[j] == 'A') inp[i][j] = 1, bgn = {i, j};
			else inp[i][j] = INF, end = {i, j};
	bfs.push (bgn);
	while (!bfs.empty ())
	{
		ll a = bfs.front ().f;
		ll b = bfs.front ().s;
		bfs.pop ();
		trav (d, dirs)
			if (valid (a + d.f, b + d.s) && inp[a + d.f][b + d.s] > inp[a][b] + 1)
			{
				inp[a + d.f][b + d.s] = inp[a][b] + 1;
				bfs.push ({a + d.f, b + d.s});
			}
	}
	if (inp[end.f][end.s] >= INF)
	{
		cout << "NO\n";
		return 0;
	}
	string path;
	for (pair <ll, ll> cur = end; cur != bgn;)
	{
		trav (d, dirs)
			if (valid (cur.f + d.f, cur.s + d.s) &&
					inp[cur.f + d.f][cur.s + d.s] < inp[cur.f][cur.s])
			{
				if (d == dirs[0]) path += 'U';
				else if (d == dirs[1]) path += 'L';
				else if (d == dirs[2]) path += 'D';
				else path += 'R';
				cur.f += d.f;
				cur.s += d.s;
				break;
			}
	}
	cout << "YES\n" << path.size () << '\n';
	for (i = path.size () - 1; i >= 0; --i)
		cout << path[i];
	cout << '\n';

	return 0;
}


