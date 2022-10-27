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
	char c;
	bool color = false;
	cin >> n >> m;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			cin >> c, color = ((c == 'C' || c == 'M' || c == 'Y')?true:color);
	if (color) cout << "#Color\n";
	else cout << "#Black&White\n";

	return 0;
}

