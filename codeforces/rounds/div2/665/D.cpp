#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, m;
		cin >> n;
		vector <vector <ll>> graph (n);
		for (i = 0; i < n - 1; ++i)
		{
			ll a, b;
			cin >> a >> b;
			--a, --b;
			graph[a].push_back (b);
			graph[b].push_back (a);
		}
		cin >> m;
		vector <ll> kf (m);
		trav (a, kf) cin >> a;
		vector <ll> qnt (n, 0), deg (n, 0);
		queue <ll> rbfs;
		for (i = 0; i < n; ++i)
		{
			deg[i] = graph[i].size ();
			if (deg[i] == 1)
				rbfs.push (i),
				--deg[i];
		}
		while (!rbfs.empty ())
		{
			ll cur = rbfs.front ();
			rbfs.pop ();
			++qnt[cur];
			trav (v, graph[cur])
			{
				if (deg[v] > 1)
					qnt[v] += qnt[cur];
				--deg[v];
				if (deg[v] == 1)
					rbfs.push (v);
			}
		}
		for (i = 0; i < n; ++i)
		{
			cout << i + 1 << ": ";
			trav (a, graph[i]) cout << a + 1 << ' ';
			cout << "| " << qnt[i] << '\n';
		}
		sort (kf.begin (), kf.end ());
		vector <ll> mult (n);
		for (i = 0; i < n; ++i)
		{
			vector <ll> sqnt (graph[i].size ());
			for (j = graph[i].size () - 2; j >= 0; --j)
				sqnt[j] = sqnt[j + 1] + qnt[graph[i][j + 1]];
			for (j = 0; j < graph[i].size (); ++j)
				mult[i] += qnt[j]*(sqnt[j] + 1);
		}
		sort (mult.begin (), mult.end ());
		ll ans = 0;
		for (i = n - 1, j = m - 1; i >= 0; --i, --j)
		{
			if (j >= 0)
				ans = (ans + mult[i]*kf[j])%MOD;
			else ans = (ans + mult[i])%MOD;
		}
		cout << ans << '\n';
	}

	return 0;
}

