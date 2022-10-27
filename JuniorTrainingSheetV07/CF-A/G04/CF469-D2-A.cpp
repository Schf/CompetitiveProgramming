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
	cin >> n;
	vector <ll> freq (n, 0);
	cin >> q;
	for (i = 0; i < q; ++i)
		cin >> j, ++freq[j - 1];
	cin >> q;
	for (i = 0; i < q; ++i)
		cin >> j, ++freq[j - 1];
	bool can = true;
	trav (a, freq)
		if (!a)
			can = false;
	if (can) cout << "I become the guy.\n";
	else cout << "Oh, my keyboard!\n";

	return 0;
}

