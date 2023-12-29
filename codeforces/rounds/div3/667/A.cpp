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
	ll i, j, n;
	cin >> n;
	ll a, b;
	for (i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (a == b) cout << "0\n";
		else cout << (abs (a - b) + 9)/10 << '\n';
	}

	return 0;
}

