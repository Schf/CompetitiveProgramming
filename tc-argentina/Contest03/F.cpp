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

vector <vector <ll>> dists;
vector <pair <ll, ll>> ans;
vector <bool> DP;

ll Dist (pair <ll, ll> a, pair <ll, ll> b)
{
	return (a.f - b.f)*(a.f - b.f) +
		(a.s - b.s)*(a.s - b.s);
}

ll Time (vector <pair <ll, ll>> path)
{
	ll sum = 0;
	trav (p, path) sum += dists[p.f][p.s];
	return sum;
}

void Solve (vector <pair <ll, ll>> path, ll state)
{
	if (DP[state]) return;
	ll i, j, n, cur;
	vector <ll> can;
	for (i = 0; i < dists.size (); ++i)
		if ((state >> i) & 1)
			can.push_back (i + 1);
	if (can.size () < 2)
	{
		if (can.size ())
			path.push_back ({0, can[0]}),
			path.push_back ({can[0], 0});
		state = (state | (1 << can[0]));
		DP[state] = true;
		trav (a, path) cout << a.f << ' ' << a.s << " | ";
		cout << Time (path) << ' ' << Time (ans) << '\n';
		if (Time (path) < Time (ans))
			ans = path;
		if (can.size ())
			path.pop_back (),
			path.pop_back ();
	}
	for (i = 0; i < can.size (); ++i)
	{
		path.push_back ({0, can[i]});
		state = (state | (1 << can[i]));
		for (j = i + 1; j < can.size (); ++j)
		{
			path.push_back ({can[i], can[j]});
			path.push_back ({can[j], 0});
			state = (state | (1 << can[j]));
			Solve (path, state);
			state = (state ^ (1 << can[j]));
			path.pop_back ();
			path.pop_back ();
		}
		path.push_back ({can[i], 0});
		Solve (path, state);
		state = (state ^ (1 << can[i]));
		path.pop_back ();
		path.pop_back ();
	}
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, dx, dy;
	cin >> dx >> dy;
	cin >> n;
	vector <pair <ll, ll>> objs (n + 1, {0, 0});
	for (i = 1; i <= n; ++i)
		cin >> objs[i].f >> objs[i].s,
		objs[i].f -= dx, objs[i].s -= dy;
	if (n == 1)
	{
		cout << 2*Dist (objs[0], objs[1]) << "\n0 1 0\n";
		return 0;
	}
	dists.resize (n + 1);
	for (i = 0; i <= n; ++i)
		for (j = 0; j <= n; ++j)
			dists[i].push_back (Dist (objs[i], objs[j]));
	DP.resize (1<<24, false);
	for (i = j = 1; i <= n; ++i)
		if (dists[0][i] > dists[0][j])
			j = i;
	for (i = 0; i < 6*n; ++i)
		ans.push_back ({0, j});
	vector <pair <ll, ll>> init;
	Solve (init, 0);
	cout << Time (ans) << '\n';
	trav (p, ans) cout << p.f << ' ';
	cout << 0 << '\n';

	return 0;
}

