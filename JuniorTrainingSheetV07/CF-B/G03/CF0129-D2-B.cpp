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
	ll i, j, n, m;
	cin >> n >> m;
	vector <set <ll>> graph (n);
	vector <ll> deg (n, 0);
	queue <ll> look;
	for (i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		--a, --b;
		graph[a].insert (b);
		graph[b].insert (a);
		++deg[a];
		++deg[b];
	}
	for (i = 0; i < n; ++i)
		if (deg[i] == 1)
			look.push (i);
	if (look.empty ())
	{
		cout << "0\n";
		return 0;
	}
	look.push (-1);
	ll ans = 0, gs = 0;
	while (!look.empty ())
	{
		ll cur = look.front ();
		look.pop ();
		if (cur < 0)
		{
			if (gs > 0)
				++ans, look.push (-1);
			gs = 0;
			continue;
		}
		if (deg[cur] == 1)
		{
			graph[*(graph[cur].begin ())].erase (cur);
			--deg[*(graph[cur].begin ())];
			if (deg[*(graph[cur].begin ())] == 1)
				look.push (*(graph[cur].begin ()));
			++gs;
		}
	}
	cout << ans << '\n';

	return 0;
}

