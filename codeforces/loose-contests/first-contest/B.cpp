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

vector <vector <ll>> mp;

inline bool valid (ll a, ll b)
{
	return 0 <= a && a < mp.size () && 0 <= b && b < mp[0].size () &&
			mp[a][b] == 0;
}

#define MAXX 307
#define MAXY 307

ll x, y;
ll pu[MAXX], pv[MAXX], cost[MAXX][MAXY];
ll pairV[MAXX], way[MAXY], minv[MAXY];
bool used[MAXY];

void hungarian() {
    memset(&pairV, 0, sizeof pairV);
    for(ll i = 1, j0 = 0; i <= x; i++) {
        pairV[0] = i;
        memset(&minv, INF, sizeof minv);
        memset(&used, false, sizeof used);
        do {
            used[j0] = true;
            ll i0 = pairV[j0], delta = INF, j1;
            for(ll j = 1; j <= y; j++) {
                if (used[j]) continue;
                ll cur = cost[i0][j] - pu[i0] - pv[j];
                if (cur < minv[j])
                    minv[j] = cur, way[j] = j0;
                if (minv[j] < delta)
                    delta = minv[j], j1 = j;
            }
            for(ll j = 0; j <= y; j++) {
                if (used[j])
                    pu[pairV[j]] += delta, pv[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while(pairV[j0] != 0);
        do {
            ll j1 = way[j0];
            pairV[j0] = pairV[j1];
            j0 = j1;
        } while(j0);
    }
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m >> x >> y;
	vector <ll> src (x), tgt (y);
	mp.resize (n, vector <ll> (m));
	trav (v, mp)
		trav (a, v)
			cin >> a;
	trav (a, src) cin >> a;
	trav (a, tgt) cin >> a;
	for (i = 0; i < x; ++i)
	{
		vector <vector <ll>> curmp (n, vector <ll> (m, INF/2));
		queue <pair <ll, ll>> bfs;
		bfs.push ({0, src[i] - 1});
		curmp[0][src[i] - 1] = 0;
		while (!bfs.empty ())
		{
			auto cur = bfs.front ();
			bfs.pop ();
			trav (d, dirs)
				if (valid (cur.f + d.f, cur.s + d.s))
					if (curmp[cur.f + d.f][cur.s + d.s] > curmp[cur.f][cur.s] + 1)
						curmp[cur.f + d.f][cur.s + d.s] = curmp[cur.f][cur.s] + 1,
						bfs.push ({cur.f + d.f, cur.s + d.s});
		}
		for (j = 0; j < y; ++j)
			cost[i + 1][j + 1] = curmp[n - 1][tgt[j] - 1];
	}
	hungarian ();
	ll ans = 0;
	for (i = 0; i < y; ++i)
		ans += cost[pairV[i + 1]][i + 1];
	if (ans >= INF/2) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}

/*
A B 1 C D
0 0 1 0 1
1 0 1 0 0
0 0 1 1 0
W X 1 Y Z

  W X Y Z
A 6 5 - -
B 5 4 - -
C - - 6 5
D - - 7 6
*/

