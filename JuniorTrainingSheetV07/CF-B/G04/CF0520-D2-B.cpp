#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+4+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	vector <ll> alg (MAXN, INF);
	queue <ll> bfs;
	alg[n] = 0;
	bfs.push (n);
	while (!bfs.empty ())
	{
		ll cur = bfs.front ();
		bfs.pop ();
		if (cur > 1 && alg[cur - 1] > alg[cur] + 1)
			alg[cur - 1] = alg[cur] + 1,
			bfs.push (cur - 1);
		if (cur*2 < MAXN && alg[2*cur] > alg[cur] + 1)
			alg[cur*2] = alg[cur] + 1,
			bfs.push (cur*2);
	}
	cout << alg[m] << '\n';

	return 0;
}

