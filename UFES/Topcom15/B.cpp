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
	ll i, j, n, q;
	cin >> n >> q;
	while (n | q)
	{
		string ref, cur;
		ll k, m;
		cin >> ref;
		for (ll qq = 0; qq < q; ++qq)
		{
			cin >> k >> m;
			m = m % (2*n);
			cur = ref;
			for (i = 0, j = 0; i < m; ++i, j = (j + k) % n)
				if (cur[j] == 'o') cur[j] = 'x';
				else cur[j] = 'o';
			cout << cur << '\n';
		}
		
	
		cin >> n >> q;
	}

	return 0;
}


