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
	ll i, j, n;
	string s, t;
	cin >> s >> t;
	trav (a, s) if (a >= 'a') a = a - 'a' + 'A';
	trav (a, t) if (a >= 'a') a = a - 'a' + 'A';
	if (s == t) cout << 0 << '\n';
	else if (s < t) cout << -1 << '\n';
	else cout << 1 << '\n';

	return 0;
}

