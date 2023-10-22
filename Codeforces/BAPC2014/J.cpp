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

inline int ctod (char c)
{
	if (c == 'R') return -1;
	if (c == 'F') return 0;
	if (c == 'L') return 1;
	return 2;
}

inline pair <int, int> dtod (int d)
{
	d = (d + 4)%4;
	if (d == 3) d = -1;
	if (d == -1) return {0, 1};
	if (d == 0) return {1, 0};
	if (d == 1) return {0, -1};
	if (d == 2) return {-1, 0};
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; cin >> tc;
	cout << tc << '\n';
	while (tc--)
	{
		ll i, j, n, dir = -1;
		string inp;
		cin >> inp;
		vector <vector <int>> maze (202, vector <int> (202, 0));
		pair <int, int> pos = {100, 0}, mx = {-INF, -INF}, mn = {INF, INF};
		for (i = 0; i < inp.size (); ++i)
		{
			for (j = -1; j < ctod (inp[i]); ++j)
				maze[pos.f + dtod (dir+j).f][pos.s + dtod (dir+j).s] = 1;
			maze[pos.f][pos.s] = 2;
			pos.f += dtod (dir+ctod (inp[i])).f;
			pos.s += dtod (dir+ctod (inp[i])).s;
			mx.f = max (mx.f, pos.f);
			mx.s = max (mx.s, pos.s);
			mn.f = min (mn.f, pos.f);
			mn.s = min (mn.s, pos.s);
			dir = (dir+j+4)%4;
			if (dir == 3) dir = -1;
		}
		cout << min (202, mx.f + 1) - max (0, mn.f - 1) + 1 << ' ';
		cout << min (202, mx.s + 1) - max (0, mn.s - 1) + 1 << '\n';
		for (i = min (202, mx.f + 1); i >= max (0, mn.f - 1); --i)
		{
			for (j = max (0, mn.s - 1); j <= min (202, mx.s + 1); ++j)
				if (maze[i][j] == 2) cout << ".";
				else cout << "#";
			cout << '\n';
		}
	}

	return 0;
}


