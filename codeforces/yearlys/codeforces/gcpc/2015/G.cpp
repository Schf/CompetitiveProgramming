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
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	bool ok = true;
	for (i = 0; i + 1 < n; ++i)
		if (inp[i] > inp[i + 1])
			ok = false;
	if (ok) cout << "yes\n";
	else cout << "no\n";

	return 0;
}

