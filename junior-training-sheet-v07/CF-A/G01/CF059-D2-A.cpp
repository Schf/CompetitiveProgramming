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
	string s;
	cin >> s;
	ll a, b; a = b = 0;
	trav (c, s)
		if (c < 'a') ++a;
		else ++b;
	if (a > b) {trav (c, s) if (c >= 'a') c = c - 'a' + 'A';}
	else {trav (c, s) if (c < 'a') c = c - 'A' + 'a';}
	cout << s << '\n';

	return 0;
}

